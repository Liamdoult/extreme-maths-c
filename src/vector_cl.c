#define CL_TARGET_OPENCL_VERSION 120
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#define OPENCL

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "extreme_maths.h"
#include "ocl_kernal_source.h"

#define MAX_SOURCE_SIZE (0x100000)

cl_int ret;
cl_context context;
cl_command_queue commandQueue;
cl_program program;

cl_kernel _vector_add;
cl_kernel _vector_iadd;
cl_kernel _vector_sub;
cl_kernel _vector_isub;
cl_kernel _vector_mul;
cl_kernel _vector_imul;
cl_kernel _vector_div;
cl_kernel _vector_idiv;

const char *getErrorString(cl_int error)
{
switch(error){
    // run-time and JIT compiler errors
    case 0: return "CL_SUCCESS";
    case -1: return "CL_DEVICE_NOT_FOUND";
    case -2: return "CL_DEVICE_NOT_AVAILABLE";
    case -3: return "CL_COMPILER_NOT_AVAILABLE";
    case -4: return "CL_MEM_OBJECT_ALLOCATION_FAILURE";
    case -5: return "CL_OUT_OF_RESOURCES";
    case -6: return "CL_OUT_OF_HOST_MEMORY";
    case -7: return "CL_PROFILING_INFO_NOT_AVAILABLE";
    case -8: return "CL_MEM_COPY_OVERLAP";
    case -9: return "CL_IMAGE_FORMAT_MISMATCH";
    case -10: return "CL_IMAGE_FORMAT_NOT_SUPPORTED";
    case -11: return "CL_BUILD_PROGRAM_FAILURE";
    case -12: return "CL_MAP_FAILURE";
    case -13: return "CL_MISALIGNED_SUB_BUFFER_OFFSET";
    case -14: return "CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST";
    case -15: return "CL_COMPILE_PROGRAM_FAILURE";
    case -16: return "CL_LINKER_NOT_AVAILABLE";
    case -17: return "CL_LINK_PROGRAM_FAILURE";
    case -18: return "CL_DEVICE_PARTITION_FAILED";
    case -19: return "CL_KERNEL_ARG_INFO_NOT_AVAILABLE";

    // compile-time errors
    case -30: return "CL_INVALID_VALUE";
    case -31: return "CL_INVALID_DEVICE_TYPE";
    case -32: return "CL_INVALID_PLATFORM";
    case -33: return "CL_INVALID_DEVICE";
    case -34: return "CL_INVALID_CONTEXT";
    case -35: return "CL_INVALID_QUEUE_PROPERTIES";
    case -36: return "CL_INVALID_COMMAND_QUEUE";
    case -37: return "CL_INVALID_HOST_PTR";
    case -38: return "CL_INVALID_MEM_OBJECT";
    case -39: return "CL_INVALID_IMAGE_FORMAT_DESCRIPTOR";
    case -40: return "CL_INVALID_IMAGE_SIZE";
    case -41: return "CL_INVALID_SAMPLER";
    case -42: return "CL_INVALID_BINARY";
    case -43: return "CL_INVALID_BUILD_OPTIONS";
    case -44: return "CL_INVALID_PROGRAM";
    case -45: return "CL_INVALID_PROGRAM_EXECUTABLE";
    case -46: return "CL_INVALID_KERNEL_NAME";
    case -47: return "CL_INVALID_KERNEL_DEFINITION";
    case -48: return "CL_INVALID_KERNEL";
    case -49: return "CL_INVALID_ARG_INDEX";
    case -50: return "CL_INVALID_ARG_VALUE";
    case -51: return "CL_INVALID_ARG_SIZE";
    case -52: return "CL_INVALID_KERNEL_ARGS";
    case -53: return "CL_INVALID_WORK_DIMENSION";
    case -54: return "CL_INVALID_WORK_GROUP_SIZE";
    case -55: return "CL_INVALID_WORK_ITEM_SIZE";
    case -56: return "CL_INVALID_GLOBAL_OFFSET";
    case -57: return "CL_INVALID_EVENT_WAIT_LIST";
    case -58: return "CL_INVALID_EVENT";
    case -59: return "CL_INVALID_OPERATION";
    case -60: return "CL_INVALID_GL_OBJECT";
    case -61: return "CL_INVALID_BUFFER_SIZE";
    case -62: return "CL_INVALID_MIP_LEVEL";
    case -63: return "CL_INVALID_GLOBAL_WORK_SIZE";
    case -64: return "CL_INVALID_PROPERTY";
    case -65: return "CL_INVALID_IMAGE_DESCRIPTOR";
    case -66: return "CL_INVALID_COMPILER_OPTIONS";
    case -67: return "CL_INVALID_LINKER_OPTIONS";
    case -68: return "CL_INVALID_DEVICE_PARTITION_COUNT";

    // extension errors
    case -1000: return "CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR";
    case -1001: return "CL_PLATFORM_NOT_FOUND_KHR";
    case -1002: return "CL_INVALID_D3D10_DEVICE_KHR";
    case -1003: return "CL_INVALID_D3D10_RESOURCE_KHR";
    case -1004: return "CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR";
    case -1005: return "CL_D3D10_RESOURCE_NOT_ACQUIRED_KHR";
    default: return "Unknown OpenCL error";
    }
}

void init() {
    // Getting platform and device information
    cl_platform_id platformId = NULL;
    cl_device_id deviceID = NULL;
    cl_uint retNumDevices;
    cl_uint retNumPlatforms;
    ret = clGetPlatformIDs(1, &platformId, &retNumPlatforms);
    ret = clGetDeviceIDs(platformId, CL_DEVICE_TYPE_DEFAULT, 1, &deviceID, &retNumDevices);

    // Creating context.
    context = clCreateContext(NULL, 1, &deviceID, NULL, NULL,  &ret);

    // Creating command queue
    commandQueue = clCreateCommandQueue(context, deviceID, 0, &ret);

    // Create program from kernel source
    program = clCreateProgramWithSource(context, 1, &kernal_source, NULL, &ret);	

    // Build program
    ret = clBuildProgram(program, 1, &deviceID, NULL, NULL, NULL);

    if(ret != CL_SUCCESS) {
        printf("CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));

        // Determine the size of the log
        size_t log_size;
        clGetProgramBuildInfo(program, deviceID, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);

        // Allocate memory for the log
        char *log = (char *) malloc(log_size);

        // Get the log
        clGetProgramBuildInfo(program, deviceID, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);

        // Print the log
        printf("%s\n", log);
    }



    // Create kernel
    _vector_add = clCreateKernel(program, "_vector_add", &ret);
    _vector_iadd = clCreateKernel(program, "_vector_iadd", &ret);
    _vector_sub = clCreateKernel(program, "_vector_sub", &ret);
    _vector_isub = clCreateKernel(program, "_vector_isub", &ret);
    _vector_mul = clCreateKernel(program, "_vector_mul", &ret);
    _vector_imul = clCreateKernel(program, "_vector_imul", &ret);
    _vector_div = clCreateKernel(program, "_vector_div", &ret);
    _vector_idiv = clCreateKernel(program, "_vector_idiv", &ret);
}

void clean() {
    ret = clFlush(commandQueue);
    ret = clFinish(commandQueue);
    ret = clReleaseCommandQueue(commandQueue);
    ret = clReleaseProgram(program);
    ret = clReleaseContext(context);
}

struct Vector create_vector(float *a, int size) {
	cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_WRITE, size * sizeof(float), NULL, &ret);
	ret = clEnqueueWriteBuffer(commandQueue, aMemObj, CL_TRUE, 0, size * sizeof(float), a, 0, NULL, NULL);;

    if(ret != CL_SUCCESS) {
        printf("create_vector CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

    struct Vector vec;
    vec.size = size;
    vec.array = aMemObj;
    return vec;
}

struct Vector generate_vector(int size) {
	cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_WRITE, size * sizeof(float), NULL, &ret);

    struct Vector vec;
    vec.size = size;
    vec.array = aMemObj;
    return vec;
}


float* get_result(struct Vector *a) {
    float *res = (float*)malloc(sizeof(float)*a->size);

    ret = clEnqueueReadBuffer(commandQueue, a->array, CL_TRUE, 0, a->size * sizeof(float), res, 0, NULL, NULL);

    if(ret != CL_SUCCESS) {
        printf("get_result CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

    return res;
}

void clean_vector(struct Vector a) {
	ret = clReleaseMemObject(a.array);
}

struct Vector vector_add(struct Vector *a, struct Vector *b) {

    struct Vector out = generate_vector(a->size);

	ret = clSetKernelArg(_vector_add, 0, sizeof(cl_mem), &(out.array));	
	ret = clSetKernelArg(_vector_add, 1, sizeof(cl_mem), &(a->array));	
	ret = clSetKernelArg(_vector_add, 2, sizeof(cl_mem), &(b->array));	
    ret = clSetKernelArg(_vector_add, 3, sizeof(unsigned int), &(a->size));

	size_t localSize = 64;
	size_t globalSize = ceil(a->size/(float)localSize)*localSize;
	ret = clEnqueueNDRangeKernel(commandQueue, _vector_add, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);	

    if(ret != CL_SUCCESS) {
        printf("CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

    return out;
}

void vector_iadd(struct Vector *a, struct Vector *b) {
	ret = clSetKernelArg(_vector_iadd, 0, sizeof(cl_mem), &(a->array));	
	ret = clSetKernelArg(_vector_iadd, 1, sizeof(cl_mem), &(b->array));	
    ret = clSetKernelArg(_vector_iadd, 2, sizeof(unsigned int), &(a->size));

	size_t localSize = 64;
	size_t globalSize = ceil(a->size/(float)localSize)*localSize;
	ret = clEnqueueNDRangeKernel(commandQueue, _vector_iadd, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);	

    if(ret != CL_SUCCESS) {
        printf("CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

}

struct Vector vector_sub(struct Vector *a, struct Vector *b) {

    struct Vector out = generate_vector(a->size);

	ret = clSetKernelArg(_vector_sub, 0, sizeof(cl_mem), &(out.array));	
	ret = clSetKernelArg(_vector_sub, 1, sizeof(cl_mem), &(a->array));	
	ret = clSetKernelArg(_vector_sub, 2, sizeof(cl_mem), &(b->array));	
    ret = clSetKernelArg(_vector_sub, 3, sizeof(unsigned int), &(a->size));

	size_t localSize = 64;
	size_t globalSize = ceil(a->size/(float)localSize)*localSize;
	ret = clEnqueueNDRangeKernel(commandQueue, _vector_sub, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);	

    if(ret != CL_SUCCESS) {
        printf("CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

    return out;
}

void vector_isub(struct Vector *a, struct Vector *b) {
	ret = clSetKernelArg(_vector_isub, 0, sizeof(cl_mem), &(a->array));	
	ret = clSetKernelArg(_vector_isub, 1, sizeof(cl_mem), &(b->array));	
    ret = clSetKernelArg(_vector_isub, 2, sizeof(unsigned int), &(a->size));

	size_t localSize = 64;
	size_t globalSize = ceil(a->size/(float)localSize)*localSize;
	ret = clEnqueueNDRangeKernel(commandQueue, _vector_isub, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);	

    if(ret != CL_SUCCESS) {
        printf("CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

}

struct Vector vector_mul(struct Vector *a, struct Vector *b) {

    struct Vector out = generate_vector(a->size);

	ret = clSetKernelArg(_vector_mul, 0, sizeof(cl_mem), &(out.array));	
	ret = clSetKernelArg(_vector_mul, 1, sizeof(cl_mem), &(a->array));	
	ret = clSetKernelArg(_vector_mul, 2, sizeof(cl_mem), &(b->array));	
    ret = clSetKernelArg(_vector_mul, 3, sizeof(unsigned int), &(a->size));

	size_t localSize = 64;
	size_t globalSize = ceil(a->size/(float)localSize)*localSize;
	ret = clEnqueueNDRangeKernel(commandQueue, _vector_mul, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);	

    if(ret != CL_SUCCESS) {
        printf("CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

    return out;
}

void vector_imul(struct Vector *a, struct Vector *b) {
	ret = clSetKernelArg(_vector_imul, 0, sizeof(cl_mem), &(a->array));	
	ret = clSetKernelArg(_vector_imul, 1, sizeof(cl_mem), &(b->array));	
    ret = clSetKernelArg(_vector_imul, 2, sizeof(unsigned int), &(a->size));

	size_t localSize = 64;
	size_t globalSize = ceil(a->size/(float)localSize)*localSize;
	ret = clEnqueueNDRangeKernel(commandQueue, _vector_imul, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);	

    if(ret != CL_SUCCESS) {
        printf("CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

}

struct Vector vector_div(struct Vector *a, struct Vector *b) {

    struct Vector out = generate_vector(a->size);

	ret = clSetKernelArg(_vector_div, 0, sizeof(cl_mem), &(out.array));	
	ret = clSetKernelArg(_vector_div, 1, sizeof(cl_mem), &(a->array));	
	ret = clSetKernelArg(_vector_div, 2, sizeof(cl_mem), &(b->array));	
    ret = clSetKernelArg(_vector_div, 3, sizeof(unsigned int), &(a->size));

	size_t localSize = 64;
	size_t globalSize = ceil(a->size/(float)localSize)*localSize;
	ret = clEnqueueNDRangeKernel(commandQueue, _vector_div, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);	

    if(ret != CL_SUCCESS) {
        printf("CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

    return out;
}

void vector_idiv(struct Vector *a, struct Vector *b) {
	ret = clSetKernelArg(_vector_idiv, 0, sizeof(cl_mem), &(a->array));	
	ret = clSetKernelArg(_vector_idiv, 1, sizeof(cl_mem), &(b->array));	
    ret = clSetKernelArg(_vector_idiv, 2, sizeof(unsigned int), &(a->size));

	size_t localSize = 64;
	size_t globalSize = ceil(a->size/(float)localSize)*localSize;
	ret = clEnqueueNDRangeKernel(commandQueue, _vector_idiv, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);	

    if(ret != CL_SUCCESS) {
        printf("CODE: %d\n", ret);
        printf("%s\n", getErrorString(ret));
    }

}
