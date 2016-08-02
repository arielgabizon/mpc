#include <sodium.h>
#include <iostream>
#include <stdexcept>
#include "algebra/curves/alt_bn128/alt_bn128_g1.hpp"
#include <assert.h>
#include "algebra/curves/alt_bn128/alt_bn128_g2.hpp"
#include "algebra/curves/alt_bn128/alt_bn128_init.hpp"
#include "algebra/curves/alt_bn128/alt_bn128_pairing.hpp"
#include "algebra/curves/alt_bn128/alt_bn128_pp.hpp"
#include "algebra/curves/public_params.hpp"
#include "relations/arithmetic_programs/qap/qap.hpp"
#include "reductions/r1cs_to_qap/r1cs_to_qap.hpp"

using namespace std;
using namespace libsnark;

typedef Fr<alt_bn128_pp> FieldT;

extern "C" void bnwrap_init() {
    assert(sodium_init() != -1);
    init_alt_bn128_params();
}

extern "C" alt_bn128_G1 bnwrap_G1_zero() {
    return alt_bn128_G1::zero();
}

extern "C" alt_bn128_G1 bnwrap_G1_one() {
    return alt_bn128_G1::one();
}

extern "C" alt_bn128_G1 bnwrap_G1_random() {
    return alt_bn128_G1::random_element();
}

extern "C" bool bnwrap_G1_is_zero(alt_bn128_G1 *p) {
    return p->is_zero();
}

extern "C" bool bnwrap_G1_is_equal(alt_bn128_G1 *p, alt_bn128_G1 *q) {
    return *p == *q;
}

extern "C" alt_bn128_G1 bnwrap_G1_add(alt_bn128_G1 *p, alt_bn128_G1 *q) {
    return *p + *q;
}

extern "C" alt_bn128_G1 bnwrap_G1_sub(alt_bn128_G1 *p, alt_bn128_G1 *q) {
    return *p - *q;
}

extern "C" alt_bn128_G1 bnwrap_G1_neg(alt_bn128_G1 *p) {
    return -(*p);
}

extern "C" alt_bn128_G1 bnwrap_G1_scalarmul(alt_bn128_G1 *p, FieldT *q) {
    return (*q) * (*p);
}

extern "C" FieldT bnwrap_fr_from(const char *a) {
    return FieldT(a);
}
