__kernel void _vector_iadd_float(__global float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        a[gid] += b[gid];
}

__kernel void _vector_add_float(__global float *c, __global const float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        c[gid] = a[gid] + b[gid];
}

__kernel void _vector_isub_float(__global float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        a[gid] -= b[gid];
}

__kernel void _vector_sub_float(__global float *c, __global const float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        c[gid] = a[gid] - b[gid];
}

__kernel void _vector_imul_float(__global float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        a[gid] *= b[gid];
}

__kernel void _vector_mul_float(__global float *c, __global const float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        c[gid] = a[gid] * b[gid];
}

__kernel void _vector_idiv_float(__global float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        a[gid] /= b[gid];
}

__kernel void _vector_div_float(__global float *c, __global const float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        c[gid] = a[gid] / b[gid];
}

