#include <xmmintrin.h> // SSE
#include <iostream>   

inline void SSESqrt_Recip_Times_X4(float* __restrict pOut, const float* __restrict pIn) {
    __m128 in = _mm_loadu_ps(pIn); // Load 4 floats unaligned
    _mm_storeu_ps(pOut, _mm_mul_ps(in, _mm_rsqrt_ps(in))); // Store 4 results unaligned
}

int main() {
    // Use an array of 4 floats
    float in[4] = {8.0f, 16.0f, 32.0f, 64.0f};
    float out[4];

    SSESqrt_Recip_Times_X4(out, in);  // square root method 

    // Print the output values
    for (int i = 0; i < 4; i++) {
        std::cout << out[i] << std::endl;
    }

    return 0;
}
