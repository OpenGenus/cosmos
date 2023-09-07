#include <assert.h>
#include "./multiply_using_bits.h"

int main() {
    
    char aa {2};
    char ab {-4};
    char ac {8};
    char ad {-16};
    unsigned char ba {2};
    unsigned char bb {4};
    unsigned char bc {8};
    unsigned char bd {16};
    short ca {2};
    short cb {-4};
    short cc {8};
    short cd {-16};
    unsigned short da {2};
    unsigned short db {4};
    unsigned short dc {8};
    unsigned short dd {16};
    int ea {2};
    int eb {-4};
    int ec {8};
    int ed {-16};
    unsigned int fa {2};
    unsigned int fb {4};
    unsigned int fc {8};
    unsigned int fd {16};
    long ga {2};
    long gb {-4};
    long gc {8};
    long gd {-16};
    unsigned long ha {2};
    unsigned long hb {4};
    unsigned long hc {8};
    unsigned long hd {16};
    long long ia {2};
    long long ib {-4};
    long long ic {8};
    long long id {-16};
    unsigned long long ja {2};
    unsigned long long jb {4};
    unsigned long long jc {8};
    unsigned long long jd {16};

    /* char */
    assert(bitwise_multiply(ac, aa) == (ac * aa));
    assert(bitwise_multiply(ac, ab) == (ac * ab));
    assert(bitwise_multiply(ad, aa) == (ad * aa));
    assert(bitwise_multiply(ad, ab) == (ad * ab));
    /* unsigned char */
    assert(bitwise_multiply(bc, ba) == (bc * ba));
    assert(bitwise_multiply(bc, bb) == (bc * bb));
    assert(bitwise_multiply(bd, ba) == (bd * ba));
    assert(bitwise_multiply(bd, bb) == (bd * bb));
    /* short */
    assert(bitwise_multiply(cc, ca) == (cc * ca));
    assert(bitwise_multiply(cc, cb) == (cc * cb));
    assert(bitwise_multiply(cd, ca) == (cd * ca));
    assert(bitwise_multiply(cd, cb) == (cd * cb));
    /* unsigned short */
    assert(bitwise_multiply(dc, da) == (dc * da));
    assert(bitwise_multiply(dc, db) == (dc * db));
    assert(bitwise_multiply(dd, da) == (dd * da));
    assert(bitwise_multiply(dd, db) == (dd * db));
    /* int */
    assert(bitwise_multiply(ec, ea) == (ec * ea));
    assert(bitwise_multiply(ec, eb) == (ec * eb));
    assert(bitwise_multiply(ed, ea) == (ed * ea));
    assert(bitwise_multiply(ed, eb) == (ed * eb));
    /* unsigned int */
    assert(bitwise_multiply(fc, fa) == (fc * fa));
    assert(bitwise_multiply(fc, fb) == (fc * fb));
    assert(bitwise_multiply(fd, fa) == (fd * fa));
    assert(bitwise_multiply(fd, fb) == (fd * fb));
    /* long */
    assert(bitwise_multiply(gc, ga) == (gc * ga));
    assert(bitwise_multiply(gc, gb) == (gc * gb));
    assert(bitwise_multiply(gd, ga) == (gd * ga));
    assert(bitwise_multiply(gd, gb) == (gd * gb));
    /* unsigned long */
    assert(bitwise_multiply(hc, ha) == (hc * ha));
    assert(bitwise_multiply(hc, hb) == (hc * hb));
    assert(bitwise_multiply(hd, ha) == (hd * ha));
    assert(bitwise_multiply(hd, hb) == (hd * hb));
    /* long long */
    assert(bitwise_multiply(ic, ia) == (ic * ia));
    assert(bitwise_multiply(ic, ib) == (ic * ib));
    assert(bitwise_multiply(id, ia) == (id * ia));
    assert(bitwise_multiply(id, ib) == (id * ib));
    /* unsigned long long */
    assert(bitwise_multiply(jc, ja) == (jc * ja));
    assert(bitwise_multiply(jc, jb) == (jc * jb));
    assert(bitwise_multiply(jd, ja) == (jd * ja));
    assert(bitwise_multiply(jd, jb) == (jd * jb));
}