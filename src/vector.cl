__kernel void _vector_iadd(__global float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        a[gid] += b[gid];
}

__kernel void _vector_add(__global float *c, __global const float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        c[gid] = a[gid] + b[gid];
}

__kernel void _vector_isub(__global float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        a[gid] -= b[gid];
}

__kernel void _vector_sub(__global float *c, __global const float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        c[gid] = a[gid] - b[gid];
}

__kernel void _vector_imul(__global float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        a[gid] *= b[gid];
}

__kernel void _vector_mul(__global float *c, __global const float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        c[gid] = a[gid] * b[gid];
}

__kernel void _vector_idiv(__global float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        a[gid] /= b[gid];
}

__kernel void _vector_div(__global float *c, __global const float *a, __global const float *b, const unsigned int n) {
    int gid = get_global_id(0);
    if (gid < n)
        c[gid] = a[gid] / b[gid];
}

