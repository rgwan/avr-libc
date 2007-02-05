/* Test of tanh() function. 500 random cases.
   $Id$
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases.	*/
    long x;		/* argument	*/
    long z;		/* tanh(x)	*/
} t[] = {

    /* x, tanh(x)	*/
    { 0x3f0b9ad7,0x3efe787e }, /*   1:  5.4533142e-01  4.9701303e-01 */
    { 0x3f22db0e,0x3f0ff150 }, /*   2:  6.3615501e-01  5.6227589e-01 */
    { 0xc0306cd8,0xbf7df188 }, /*   3: -2.7566433e+00 -9.9196672e-01 */
    { 0x3ecbfdd9,0x3ec1d77d }, /*   4:  3.9842108e-01  3.7859717e-01 */
    { 0x3edb0811,0x3ece94a0 }, /*   5:  4.2779592e-01  4.0347767e-01 */
    { 0x3e263270,0x3e24c0c0 }, /*   6:  1.6230178e-01  1.6089153e-01 */
    { 0x3ea3e5b8,0x3e9e84f7 }, /*   7:  3.2011199e-01  3.0960819e-01 */
    { 0x3edaa37d,0x3ece4065 }, /*   8:  4.2702857e-01  4.0283504e-01 */
    { 0x3e66536d,0x3e6284c7 }, /*   9:  2.2492762e-01  2.2120963e-01 */
    { 0x3f3af2c0,0x3f1f8be6 }, /*  10:  7.3026657e-01  6.2322843e-01 */
    { 0xbecce0d3,0xbec299ce }, /*  11: -4.0015277e-01 -3.8007969e-01 */
    { 0x3f0e96a7,0x3f01780b }, /*  12:  5.5698627e-01  5.0573796e-01 */
    { 0x3f06bd84,0x3ef71370 }, /*  13:  5.2632928e-01  4.8257017e-01 */
    { 0x3ef7ef0a,0x3ee636dd }, /*  14:  4.8424560e-01  4.4963732e-01 */
    { 0xbf0f2ef7,0xbf01e944 }, /*  15: -5.5931038e-01 -5.0746560e-01 */
    { 0x3f2010f6,0x3f0e05fd }, /*  16:  6.2525880e-01  5.5477887e-01 */
    { 0x3e5fe530,0x3e5c64f0 }, /*  17:  2.1864772e-01  2.1522880e-01 */
    { 0xc0af0a98,0xbf7ffdad }, /*  18: -5.4700432e+00 -9.9996454e-01 */
    { 0xc0b0c272,0xbf7ffdea }, /*  19: -5.5237360e+00 -9.9996817e-01 */
    { 0x3ec8d065,0x3ebf1d00 }, /*  20:  3.9221492e-01  3.7326813e-01 */
    { 0xbf0faea9,0xbf0247fb }, /*  21: -5.6125885e-01 -5.0891083e-01 */
    { 0xbf3120e1,0xbf196595 }, /*  22: -6.9190794e-01 -5.9920627e-01 */
    { 0x3eb01087,0x3ea9701a }, /*  23:  3.4387609e-01  3.3093339e-01 */
    { 0x3eb1decf,0x3eab0b47 }, /*  24:  3.4740302e-01  3.3407041e-01 */
    { 0x40f39f56,0x3f7ffff8 }, /*  25:  7.6132002e+00  9.9999952e-01 */
    { 0x3f0be06f,0x3efee13e }, /*  26:  5.4639333e-01  4.9781221e-01 */
    { 0xbf03eb2b,0xbef2b94b }, /*  27: -5.1530713e-01 -4.7406992e-01 */
    { 0x3ef2f860,0x3ee23cb0 }, /*  28:  4.7455120e-01  4.4186926e-01 */
    { 0x3f09e317,0x3efbe00b }, /*  29:  5.3862137e-01  4.9194369e-01 */
    { 0x3fe0fa0e,0x3f713680 }, /*  30:  1.7576311e+00  9.4223785e-01 */
    { 0xbf25892c,0xbf11c3bf }, /*  31: -6.4662433e-01 -5.6939310e-01 */
    { 0xbf08ab33,0xbefa061e }, /*  32: -5.3386229e-01 -4.8832792e-01 */
    { 0xbf0a11b7,0xbefc26b3 }, /*  33: -5.3933281e-01 -4.9248275e-01 */
    { 0x3ec878d0,0x3ebed19a }, /*  34:  3.9154673e-01  3.7269288e-01 */
    { 0xbf0d5b46,0xbf008cc2 }, /*  35: -5.5217397e-01 -5.0214779e-01 */
    { 0xbef4a16d,0xbee39242 }, /*  36: -4.7779408e-01 -4.4447523e-01 */
    { 0x3f0d12a1,0x3f005666 }, /*  37:  5.5106550e-01  5.0131834e-01 */
    { 0x3f108e58,0x3f02ed72 }, /*  38:  5.6467199e-01  5.1143563e-01 */
    { 0xbec2a025,0xbeb9c35e }, /*  39: -3.8012806e-01 -3.6281866e-01 */
    { 0x3f2d128b,0x3f16c5bd }, /*  40:  6.7606419e-01  5.8895475e-01 */
    { 0xbf4d7090,0xbf2a59b7 }, /*  41: -8.0249882e-01 -6.6543144e-01 */
    { 0x3f0f5b5a,0x3f020a36 }, /*  42:  5.5998766e-01  5.0796831e-01 */
    { 0x3eb47ac1,0x3ead5baa }, /*  43:  3.5249904e-01  3.3858997e-01 */
    { 0xbf5733f6,0xbf2fa745 }, /*  44: -8.4063661e-01 -6.8614608e-01 */
    { 0xbe57f169,0xbe54cc41 }, /*  45: -2.1088184e-01 -2.0781042e-01 */
    { 0xbee09980,0xbed338bf }, /*  46: -4.3867111e-01 -4.1254231e-01 */
    { 0xbf43d836,0xbf24deb2 }, /*  47: -7.6501787e-01 -6.4402306e-01 */
    { 0xbf0637f6,0xbef64655 }, /*  48: -5.2429140e-01 -4.8100534e-01 */
    { 0xbf4c92ed,0xbf29ddf1 }, /*  49: -7.9911691e-01 -6.6354281e-01 */
    { 0xbfb8f304,0xbf6509f3 }, /*  50: -1.4449162e+00 -8.9468306e-01 */
    { 0x3ebd409e,0x3eb51464 }, /*  51:  3.6963362e-01  3.5367119e-01 */
    { 0xbf2538e7,0xbf118d76 }, /*  52: -6.4539951e-01 -5.6856477e-01 */
    { 0x3f0b7216,0x3efe3b1a }, /*  53:  5.4470956e-01  4.9654466e-01 */
    { 0x3f4548fe,0x3f25b5bd }, /*  54:  7.7064502e-01  6.4730436e-01 */
    { 0x408e5a86,0x3f7fee13 }, /*  55:  4.4485502e+00  9.9972647e-01 */
    { 0x3f29d4d2,0x3f14a3c7 }, /*  56:  6.6340363e-01  5.8062404e-01 */
    { 0xbe5e8bc7,0xbe5b1b6f }, /*  57: -2.1733008e-01 -2.1397184e-01 */
    { 0xbf03dd10,0xbef2a36c }, /*  58: -5.1509190e-01 -4.7390306e-01 */
    { 0xbef61b2c,0xbee4c0fd }, /*  59: -4.8067605e-01 -4.4678488e-01 */
    { 0xbf3b7301,0xbf1fda3d }, /*  60: -7.3222357e-01 -6.2442380e-01 */
    { 0xbeefc53f,0xbedfa7ad }, /*  61: -4.6830174e-01 -4.3682614e-01 */
    { 0xbed86e0f,0xbecc65e6 }, /*  62: -4.2271468e-01 -3.9921492e-01 */
    { 0x3f201f17,0x3f0e0fc5 }, /*  63:  6.2547439e-01  5.5492812e-01 */
    { 0xbc35724e,0xbc357068 }, /*  64: -1.1074616e-02 -1.1074163e-02 */
    { 0xbedc7fcb,0xbecfced3 }, /*  65: -4.3066248e-01 -4.0587482e-01 */
    { 0x3f1e5460,0x3f0cd115 }, /*  66:  6.1847496e-01  5.5006534e-01 */
    { 0x3f73054a,0x3f3d4da0 }, /*  67:  9.4929945e-01  7.3946571e-01 */
    { 0xbfa667c1,0xbf5c9a96 }, /*  68: -1.3000413e+00 -8.6173379e-01 */
    { 0x3ecfd366,0x3ec51df4 }, /*  69:  4.0590972e-01  3.8499415e-01 */
    { 0x3f0fed29,0x3f027646 }, /*  70:  5.6221253e-01  5.0961721e-01 */
    { 0x3efab1d7,0x3ee86966 }, /*  71:  4.8963806e-01  4.5392913e-01 */
    { 0xbef26805,0xbee1c876 }, /*  72: -4.7344986e-01 -4.4098252e-01 */
    { 0xbf0d5726,0xbf0089ac }, /*  73: -5.5211103e-01 -5.0210071e-01 */
    { 0xbef38b6a,0xbee2b2f5 }, /*  74: -4.7567302e-01 -4.4277158e-01 */
    { 0x3f12169b,0x3f040e38 }, /*  75:  5.7065743e-01  5.1584196e-01 */
    { 0xbf469087,0xbf26736c }, /*  76: -7.7564281e-01 -6.5019870e-01 */
    { 0x3ed17a10,0x3ec68586 }, /*  77:  4.0913439e-01  3.8773745e-01 */
    { 0xbeeddcb3,0xbede1bb5 }, /*  78: -4.6457443e-01 -4.3380514e-01 */
    { 0x3f3e1c2f,0x3f217721 }, /*  79:  7.4261755e-01  6.3072401e-01 */
    { 0x3e92b766,0x3e8ed407 }, /*  80:  2.8655547e-01  2.7896139e-01 */
    { 0x3eccf7e6,0x3ec2ad8b }, /*  81:  4.0032881e-01  3.8023028e-01 */
    { 0x3ef2b61d,0x3ee2075a }, /*  82:  4.7404566e-01  4.4146234e-01 */
    { 0x3f90a4a1,0x3f4f9f80 }, /*  83:  1.1300241e+00  8.1102753e-01 */
    { 0x4035600f,0x3f7e3cba }, /*  84:  2.8339880e+00  9.9311411e-01 */
    { 0x3eacdf86,0x3ea69715 }, /*  85:  3.3764285e-01  3.2537141e-01 */
    { 0xbec1479b,0xbeb897e6 }, /*  86: -3.7749943e-01 -3.6053389e-01 */
    { 0xbf7dbb9d,0xbf420270 }, /*  87: -9.9114400e-01 -7.5784969e-01 */
    { 0xbf330f0b,0xbf1aa0e4 }, /*  88: -6.9944829e-01 -6.0401750e-01 */
    { 0x3f0ea81a,0x3f018507 }, /*  89:  5.5725253e-01  5.0593609e-01 */
    { 0x3ef4ea0d,0x3ee3cc85 }, /*  90:  4.7834817e-01  4.4491974e-01 */
    { 0xbf21e3b3,0xbf0f47cc }, /*  91: -6.3238066e-01 -5.5968928e-01 */
    { 0x3cb54093,0x3cb53901 }, /*  92:  2.2125518e-02  2.2121908e-02 */
    { 0x3ef0af58,0x3ee064f4 }, /*  93:  4.7008777e-01  4.3827021e-01 */
    { 0x3f0e099a,0x3f010ef4 }, /*  94:  5.5483401e-01  5.0413442e-01 */
    { 0x3ed8503c,0x3ecc4cd4 }, /*  95:  4.2248714e-01  3.9902365e-01 */
    { 0xbedfb733,0xbed27cd4 }, /*  96: -4.3694457e-01 -4.1110861e-01 */
    { 0x3f482bd9,0x3f275fe2 }, /*  97:  7.8191906e-01  6.5380681e-01 */
    { 0x3efb4fd3,0x3ee8e6c3 }, /*  98:  4.9084339e-01  4.5488557e-01 */
    { 0x3ecf7bd9,0x3ec4d35c }, /*  99:  4.0524176e-01  3.8442504e-01 */
    { 0xbee302b4,0xbed537e9 }, /* 100: -4.4338000e-01 -4.1644219e-01 */
    { 0xc003ba15,0xbf77c989 }, /* 101: -2.0582325e+00 -9.6791893e-01 */
    { 0x40b9b9f1,0x3f7ffecf }, /* 102:  5.8039479e+00  9.9998182e-01 */
    { 0x3ee47c60,0x3ed66fb6 }, /* 103:  4.4626141e-01  4.1882104e-01 */
    { 0xbef6e93e,0xbee565cf }, /* 104: -4.8224825e-01 -4.4804236e-01 */
    { 0xbe776696,0xbe72b261 }, /* 105: -2.4160227e-01 -2.3700859e-01 */
    { 0x3ed96ca5,0x3ecd3bbf }, /* 106:  4.2465702e-01  4.0084645e-01 */
    { 0xbedb17d8,0xbecea1d6 }, /* 107: -4.2791629e-01 -4.0357846e-01 */
    { 0x3fc486ab,0x3f694d67 }, /* 108:  1.5353597e+00  9.1133732e-01 */
    { 0xb404283c,0xb404283c }, /* 109: -1.2308095e-07 -1.2308095e-07 */
    { 0xbf421f20,0xbf23db70 }, /* 110: -7.5828743e-01 -6.4006710e-01 */
    { 0xbe47c78b,0xbe454862 }, /* 111: -1.9509713e-01 -1.9265893e-01 */
    { 0xbe13d079,0xbe12cbd2 }, /* 112: -1.4434995e-01 -1.4335564e-01 */
    { 0xbf66d49c,0xbf3794e5 }, /* 113: -9.0168166e-01 -7.1711570e-01 */
    { 0xbf5f4fef,0xbf33da29 }, /* 114: -8.7231344e-01 -7.0254761e-01 */
    { 0x3ef3f957,0x3ee30b4d }, /* 115:  4.7651169e-01  4.4344559e-01 */
    { 0x3f2d17cb,0x3f16c92b }, /* 116:  6.7614430e-01  5.8900708e-01 */
    { 0x3f40b20f,0x3f23032a }, /* 117:  7.5271696e-01  6.3676703e-01 */
    { 0x4080f5a5,0x3f7fd69a }, /* 118:  4.0299859e+00  9.9936831e-01 */
    { 0xbf0bf9d2,0xbeff076d }, /* 119: -5.4678071e-01 -4.9810353e-01 */
    { 0xbf0fb63c,0xbf024d98 }, /* 120: -5.6137443e-01 -5.0899649e-01 */
    { 0xbed9f72a,0xbecdaff6 }, /* 121: -4.2571384e-01 -4.0173310e-01 */
    { 0xbf4d1f5a,0xbf2a2c6d }, /* 122: -8.0125964e-01 -6.6474038e-01 */
    { 0x3ed6309c,0x3eca8301 }, /* 123:  4.1833961e-01  3.9553073e-01 */
    { 0xbeb523ad,0xbeadf127 }, /* 124: -3.5378781e-01 -3.3973047e-01 */
    { 0xbf0c8624,0xbeffda36 }, /* 125: -5.4892182e-01 -4.9971169e-01 */
    { 0x3ecd7bef,0x3ec31e72 }, /* 126:  4.0133616e-01  3.8109165e-01 */
    { 0x430362fd,0x3f800000 }, /* 127:  1.3138667e+02  1.0000000e+00 */
    { 0x3f06bc94,0x3ef71200 }, /* 128:  5.2631497e-01  4.8255920e-01 */
    { 0x3ef1d00e,0x3ee14dfc }, /* 129:  4.7229046e-01  4.4004810e-01 */
    { 0x3f0bce5b,0x3efec60b }, /* 130:  5.4611748e-01  4.9760470e-01 */
    { 0x3f2dc71a,0x3f173b7a }, /* 131:  6.7881930e-01  5.9075129e-01 */
    { 0xbed2ef96,0xbec7c28a }, /* 132: -4.1198415e-01 -3.9015609e-01 */
    { 0xbd8052d1,0xbd8027e5 }, /* 133: -6.2657960e-02 -6.2576093e-02 */
    { 0xbad03a93,0xbad03a88 }, /* 134: -1.5886597e-03 -1.5886584e-03 */
    { 0x3eedffe9,0x3ede384a }, /* 135:  4.6484306e-01  4.3402320e-01 */
    { 0x3ef362b0,0x3ee29236 }, /* 136:  4.7536230e-01  4.4252175e-01 */
    { 0xbff53960,0xbf75235f }, /* 137: -1.9158134e+00 -9.5757097e-01 */
    { 0x3e83ba28,0x3e80e54a }, /* 138:  2.5727963e-01  2.5174934e-01 */
    { 0x3f295c0f,0x3f1453a4 }, /* 139:  6.6156095e-01  5.7940125e-01 */
    { 0x3ed24547,0x3ec73215 }, /* 140:  4.1068479e-01  3.8905397e-01 */
    { 0x3e9e63e0,0x3e99860e }, /* 141:  3.0935574e-01  2.9985088e-01 */
    { 0xbee5b52f,0xbed77164 }, /* 142: -4.4864795e-01 -4.2078698e-01 */
    { 0x3ed3500d,0x3ec8144c }, /* 143:  4.1272011e-01  3.9077985e-01 */
    { 0x3ef813f9,0x3ee65453 }, /* 144:  4.8452738e-01  4.4986209e-01 */
    { 0xbf0b12e5,0xbefdab8e }, /* 145: -5.4325706e-01 -4.9544948e-01 */
    { 0xc0b7b5d6,0xbf7ffea6 }, /* 146: -5.7409468e+00 -9.9997938e-01 */
    { 0xbf2cda07,0xbf16a0cf }, /* 147: -6.7520183e-01 -5.8839124e-01 */
    { 0x3f0999a3,0x3efb70a1 }, /* 148:  5.3750056e-01  4.9109367e-01 */
    { 0xbf4065a0,0xbf22d5b1 }, /* 149: -7.5155067e-01 -6.3607317e-01 */
    { 0x3ed6aa9f,0x3ecae9e3 }, /* 150:  4.1927049e-01  3.9631566e-01 */
    { 0xbf9a59a2,0xbf55def7 }, /* 151: -1.2058604e+00 -8.3543342e-01 */
    { 0xbea508ff,0xbe9f8c23 }, /* 152: -3.2233426e-01 -3.1161603e-01 */
    { 0xbed9efcd,0xbecda9c9 }, /* 153: -4.2565766e-01 -4.0168598e-01 */
    { 0x4489d32c,0x3f800000 }, /* 154:  1.1025991e+03  1.0000000e+00 */
    { 0xbef3f874,0xbee30a97 }, /* 155: -4.7650492e-01 -4.4344017e-01 */
    { 0x3ee9ac04,0x3edab1cf }, /* 156:  4.5639050e-01  4.2713782e-01 */
    { 0x3ea625e4,0x3ea08d32 }, /* 157:  3.2450783e-01  3.1357723e-01 */
    { 0x3ee4efee,0x3ed6cef6 }, /* 158:  4.4714302e-01  4.1954774e-01 */
    { 0x3ef89fa9,0x3ee6c3b1 }, /* 159:  4.8559311e-01  4.5071176e-01 */
    { 0x3ed26381,0x3ec74bbb }, /* 160:  4.1091540e-01  3.8924965e-01 */
    { 0xc1d26145,0xbf800000 }, /* 161: -2.6297495e+01 -1.0000000e+00 */
    { 0x3ed7b0cb,0x3ecbc6b5 }, /* 162:  4.2127070e-01  3.9800039e-01 */
    { 0xbbc69481,0xbbc693e2 }, /* 163: -6.0601835e-03 -6.0601095e-03 */
    { 0xbe6f9f13,0xbe6b5762 }, /* 164: -2.3400526e-01 -2.2982553e-01 */
    { 0x3ec9a6a9,0x3ebfd54d }, /* 165:  3.9384964e-01  3.7467423e-01 */
    { 0xbf086262,0xbef99727 }, /* 166: -5.3275120e-01 -4.8748133e-01 */
    { 0xbedf849b,0xbed252c7 }, /* 167: -4.3655857e-01 -4.1078779e-01 */
    { 0xbef50e82,0xbee3e9c2 }, /* 168: -4.7862631e-01 -4.4514281e-01 */
    { 0xbf0c0db8,0xbeff2558 }, /* 169: -5.4708433e-01 -4.9833179e-01 */
    { 0x3f41dc7e,0x3f23b414 }, /* 170:  7.5727069e-01  6.3946652e-01 */
    { 0xbf8d07e7,0xbf4d17e7 }, /* 171: -1.1018037e+00 -8.0114597e-01 */
    { 0xbea61815,0xbea080be }, /* 172: -3.2440248e-01 -3.1348222e-01 */
    { 0x402b785a,0x3f7d99c6 }, /* 173:  2.6792207e+00  9.9062765e-01 */
    { 0xbef1516d,0xbee0e7d5 }, /* 174: -4.7132435e-01 -4.3926874e-01 */
    { 0x3f2c4d56,0x3f1644b5 }, /* 175:  6.7305505e-01  5.8698589e-01 */
    { 0x3da3c98e,0x3da37064 }, /* 176:  7.9974279e-02  7.9804212e-02 */
    { 0x3f0efdf7,0x3f01c4de }, /* 177:  5.5856270e-01  5.0691020e-01 */
    { 0x3f0bc457,0x3efeb6f8 }, /* 178:  5.4596466e-01  4.9748969e-01 */
    { 0xbef4915f,0xbee38560 }, /* 179: -4.7767159e-01 -4.4437695e-01 */
    { 0xbed3bcc7,0xbec87064 }, /* 180: -4.1354963e-01 -3.9148247e-01 */
    { 0x3edfc1cb,0x3ed285a1 }, /* 181:  4.3702540e-01  4.1117576e-01 */
    { 0x3f0cfc6b,0x3f0045c5 }, /* 182:  5.5072659e-01  5.0106460e-01 */
    { 0x3f10ce55,0x3f031cac }, /* 183:  5.6564838e-01  5.1215625e-01 */
    { 0xbf53b90c,0xbf2dcb63 }, /* 184: -8.2704234e-01 -6.7888469e-01 */
    { 0xc5560fb8,0xbf800000 }, /* 185: -3.4249824e+03 -1.0000000e+00 */
    { 0x3ec121d3,0x3eb87707 }, /* 186:  3.7721118e-01  3.6028311e-01 */
    { 0xbf24c605,0xbf113fa4 }, /* 187: -6.4364654e-01 -5.6737733e-01 */
    { 0xb8b849be,0xb8b849be }, /* 188: -8.7875393e-05 -8.7875393e-05 */
    { 0xbf436551,0xbf249b61 }, /* 189: -7.6326472e-01 -6.4299589e-01 */
    { 0x3f23c72a,0x3f109272 }, /* 190:  6.3975775e-01  5.6473458e-01 */
    { 0x3f0c575d,0x3eff93ff }, /* 191:  5.4820806e-01  4.9917600e-01 */
    { 0xbeb8c7f9,0xbeb127d8 }, /* 192: -3.6090067e-01 -3.4600711e-01 */
    { 0x3f70a487,0x3f3c37d7 }, /* 193:  9.4001049e-01  7.3522705e-01 */
    { 0x3f2d5f7b,0x3f16f7f4 }, /* 194:  6.7723817e-01  5.8972096e-01 */
    { 0xbf51fefb,0xbf2cdbf8 }, /* 195: -8.2029694e-01 -6.7523146e-01 */
    { 0x3f5b25e6,0x3f31b81a }, /* 196:  8.5604703e-01  6.9421542e-01 */
    { 0xbec5a245,0xbebc5eb0 }, /* 197: -3.8600364e-01 -3.6790991e-01 */
    { 0x3ef1fd1d,0x3ee17250 }, /* 198:  4.7263423e-01  4.4032526e-01 */
    { 0xbf1c16b6,0xbf0b3f11 }, /* 199: -6.0972154e-01 -5.4393107e-01 */
    { 0x3f08113a,0x3ef91b56 }, /* 200:  5.3151286e-01  4.8653668e-01 */
    { 0x3f34da3f,0x3f1bc353 }, /* 201:  7.0645517e-01  6.0844916e-01 */
    { 0xbf3d275e,0xbf20e35b }, /* 202: -7.3888195e-01 -6.2846917e-01 */
    { 0x3f4beb3d,0x3f297fed }, /* 203:  7.9655820e-01  6.6210824e-01 */
    { 0xbe9967e7,0xbe94f971 }, /* 204: -2.9962084e-01 -2.9096559e-01 */
    { 0x3ef40584,0x3ee31515 }, /* 205:  4.7660458e-01  4.4352022e-01 */
    { 0x3f4fa55d,0x3f2b929f }, /* 206:  8.1111699e-01  6.7020601e-01 */
    { 0xbeb7dbc2,0xbeb057c8 }, /* 207: -3.5909849e-01 -3.4441972e-01 */
    { 0x3f27b1b0,0x3f133757 }, /* 208:  6.5505505e-01  5.7506317e-01 */
    { 0x3f2be85b,0x3f160276 }, /* 209:  6.7151421e-01  5.8597505e-01 */
    { 0xc129c74b,0xbf800000 }, /* 210: -1.0611156e+01 -1.0000000e+00 */
    { 0x3f84897e,0x3f46ad66 }, /* 211:  1.0354459e+00  7.7608335e-01 */
    { 0x3f258f7c,0x3f11c803 }, /* 212:  6.4672065e-01  5.6945819e-01 */
    { 0x3f24785b,0x3f110af1 }, /* 213:  6.4246148e-01  5.6657320e-01 */
    { 0x3eb2f7e2,0x3eac04cd }, /* 214:  3.4954745e-01  3.3597413e-01 */
    { 0xbef2418c,0xbee1a977 }, /* 215: -4.7315633e-01 -4.4074604e-01 */
    { 0x3ef3938c,0x3ee2b97f }, /* 216:  4.7573507e-01  4.4282147e-01 */
    { 0x3f256d86,0x3f11b10f }, /* 217:  6.4620245e-01  5.6910795e-01 */
    { 0xbeb81c9e,0xbeb090f0 }, /* 218: -3.5959333e-01 -3.4485579e-01 */
    { 0x3f2a17b3,0x3f14d016 }, /* 219:  6.6442412e-01  5.8130014e-01 */
    { 0xbe9849b6,0xbe93f350 }, /* 220: -2.9743737e-01 -2.8896570e-01 */
    { 0x3f3ffb88,0x3f229675 }, /* 221:  7.4993181e-01  6.3510829e-01 */
    { 0x3f33320c,0x3f1ab71d }, /* 222:  6.9998240e-01  6.0435659e-01 */
    { 0x3f0e2e9b,0x3f012a8c }, /* 223:  5.5539864e-01  5.0455546e-01 */
    { 0xb7b64a3a,0xb7b64a3a }, /* 224: -2.1730655e-05 -2.1730655e-05 */
    { 0xbddb749d,0xbdda9e91 }, /* 225: -1.0715602e-01 -1.0674775e-01 */
    { 0xbeef6deb,0xbedf60fd }, /* 226: -4.6763548e-01 -4.3628684e-01 */
    { 0x3f0a2a5b,0x3efc4c06 }, /* 227:  5.3970879e-01  4.9276751e-01 */
    { 0x3f6c8257,0x3f3a4bde }, /* 228:  9.2386383e-01  7.2772014e-01 */
    { 0x3ef031f2,0x3edfff9a }, /* 229:  4.6913105e-01  4.3749696e-01 */
    { 0x3caa8b83,0x3caa8535 }, /* 230:  2.0818477e-02  2.0815471e-02 */
    { 0xbf697c00,0xbf38dc76 }, /* 231: -9.1204834e-01 -7.2211397e-01 */
    { 0x3ee3797c,0x3ed59a0e }, /* 232:  4.4428623e-01  4.1719097e-01 */
    { 0xbf0ee1c2,0xbf01afe8 }, /* 233: -5.5813229e-01 -5.0659037e-01 */
    { 0xc042fbe4,0xbf7ed8b3 }, /* 234: -3.0466242e+00 -9.9549407e-01 */
    { 0xbf0c70fa,0xbeffba73 }, /* 235: -5.4859889e-01 -4.9946937e-01 */
    { 0xbf6dbb7d,0xbf3adeab }, /* 236: -9.2864209e-01 -7.2996014e-01 */
    { 0x3f46bef7,0x3f268e37 }, /* 237:  7.7635139e-01  6.5060753e-01 */
    { 0xbf111770,0xbf035292 }, /* 238: -5.6676388e-01 -5.1297867e-01 */
    { 0x3f365904,0x3f1cb388 }, /* 239:  7.1229577e-01  6.1211443e-01 */
    { 0x3ed3c21f,0x3ec874ea }, /* 240:  4.1359040e-01  3.9151698e-01 */
    { 0xbf071b2c,0xbef7a308 }, /* 241: -5.2775836e-01 -4.8366570e-01 */
    { 0x3eb1a8fa,0x3eaadb72 }, /* 242:  3.4699231e-01  3.3370548e-01 */
    { 0xbf0de2bb,0xbf00f1f4 }, /* 243: -5.5424088e-01 -5.0369191e-01 */
    { 0x3ed4e484,0x3ec96a95 }, /* 244:  4.1580594e-01  3.9339128e-01 */
    { 0xbf3a72b3,0xbf1f3d7d }, /* 245: -7.2831267e-01 -6.2203199e-01 */
    { 0xbe1ddcf3,0xbe1c9fcf }, /* 246: -1.5416317e-01 -1.5295337e-01 */
    { 0xbe64ae6f,0xbe60f43e }, /* 247: -2.2332166e-01 -2.1968171e-01 */
    { 0x3ef4cb3f,0x3ee3b3cf }, /* 248:  4.7811314e-01  4.4473121e-01 */
    { 0x3f08f71f,0x3efa79af }, /* 249:  5.3502077e-01  4.8920962e-01 */
    { 0x3ebbe3c2,0x3eb3e2e2 }, /* 250:  3.6697203e-01  3.5134035e-01 */
    { 0x3ebf09e5,0x3eb6a3fa }, /* 251:  3.7312236e-01  3.5671979e-01 */
    { 0xbeb0a264,0xbea9f1f2 }, /* 252: -3.4498894e-01 -3.3192402e-01 */
    { 0x3f2dce19,0x3f174008 }, /* 253:  6.7892605e-01  5.9082079e-01 */
    { 0x3f3a4dd3,0x3f1f26df }, /* 254:  7.2775000e-01  6.2168688e-01 */
    { 0x3f0db45c,0x3f00cf56 }, /* 255:  5.5353332e-01  5.0316370e-01 */
    { 0xbf750d6d,0xbf3e37f8 }, /* 256: -9.5723611e-01 -7.4304152e-01 */
    { 0x3f0832f8,0x3ef94ed5 }, /* 257:  5.3202772e-01  4.8692957e-01 */
    { 0xbed3a153,0xbec85925 }, /* 258: -4.1334018e-01 -3.9130512e-01 */
    { 0xbf0560fd,0xbef4fb57 }, /* 259: -5.2101117e-01 -4.7848007e-01 */
    { 0x5082cfda,0x3f800000 }, /* 260:  1.7557279e+10  1.0000000e+00 */
    { 0xbed58171,0xbec9ef29 }, /* 261: -4.1700318e-01 -3.9440277e-01 */
    { 0x3f28eab2,0x3f140843 }, /* 262:  6.5983117e-01  5.7825106e-01 */
    { 0x3f59cce6,0x3f3104b7 }, /* 263:  8.5078275e-01  6.9147819e-01 */
    { 0x3f445235,0x3f252602 }, /* 264:  7.6687938e-01  6.4511120e-01 */
    { 0xbf0677ac,0xbef6a83a }, /* 265: -5.2526355e-01 -4.8175222e-01 */
    { 0xbf9ee528,0xbf588953 }, /* 266: -1.2413683e+00 -8.4584540e-01 */
    { 0xbfbc5f78,0xbf665f79 }, /* 267: -1.4716635e+00 -8.9989430e-01 */
    { 0xbef966b4,0xbee76231 }, /* 268: -4.8711169e-01 -4.5192102e-01 */
    { 0x3f3190a8,0x3f19ad28 }, /* 269:  6.9361353e-01  6.0029840e-01 */
    { 0xbed9e863,0xbecda391 }, /* 270: -4.2560109e-01 -4.0163854e-01 */
    { 0x3fa64515,0x3f5c88b8 }, /* 271:  1.2989832e+00  8.6146116e-01 */
    { 0xbef370a7,0xbee29d71 }, /* 272: -4.7546884e-01 -4.4260743e-01 */
    { 0xbecb738c,0xbec160f7 }, /* 273: -3.9736593e-01 -3.7769291e-01 */
    { 0x3efa8d84,0x3ee84c8e }, /* 274:  4.8936093e-01  4.5370907e-01 */
    { 0xbdde3631,0xbddd5801 }, /* 275: -1.0850180e-01 -1.0807801e-01 */
    { 0xbf544b8c,0xbf2e1a3f }, /* 276: -8.2927775e-01 -6.8008798e-01 */
    { 0x3ea06db2,0x3e9b6063 }, /* 277:  3.1333691e-01  3.0346975e-01 */
    { 0xbf3900be,0xbf1e59e1 }, /* 278: -7.2266757e-01 -6.1855894e-01 */
    { 0x3ea50ba4,0x3e9f8e87 }, /* 279:  3.2235444e-01  3.1163427e-01 */
    { 0xc4deb5a1,0xbf800000 }, /* 280: -1.7816759e+03 -1.0000000e+00 */
    { 0x3f0d593e,0x3f008b3d }, /* 281:  5.5214298e-01  5.0212461e-01 */
    { 0xc055f774,0xbf7f5caa }, /* 282: -3.3432283e+00 -9.9750769e-01 */
    { 0xbf3af6c7,0xbf1f8e5c }, /* 283: -7.3032802e-01 -6.2326598e-01 */
    { 0x3f32ed00,0x3f1a8b42 }, /* 284:  6.9892883e-01  6.0368741e-01 */
    { 0xbfcd5c55,0xbf6c1d82 }, /* 285: -1.6043802e+00 -9.2232525e-01 */
    { 0x3e5ebc19,0x3e5b498b }, /* 286:  2.1751441e-01  2.1414773e-01 */
    { 0x3e9fa369,0x3e9aa8a5 }, /* 287:  3.1179360e-01  3.0206791e-01 */
    { 0x3e7fd571,0x3e7aa3f3 }, /* 288:  2.4983765e-01  2.4476604e-01 */
    { 0x3f028b72,0x3ef0968f }, /* 289:  5.0994027e-01  4.6989867e-01 */
    { 0xbf52462d,0xbf2d02ad }, /* 290: -8.2138330e-01 -6.7582208e-01 */
    { 0xbf07ff6f,0xbef9002b }, /* 291: -5.3124136e-01 -4.8632941e-01 */
    { 0x3f1ffcff,0x3f0df82b }, /* 292:  6.2495416e-01  5.5456799e-01 */
    { 0x3f05f70c,0x3ef5e27e }, /* 293:  5.2330089e-01  4.8024362e-01 */
    { 0x3eeeafa7,0x3edec6d8 }, /* 294:  4.6618387e-01  4.3511081e-01 */
    { 0xbebc2efa,0xbeb424cd }, /* 295: -3.6754590e-01 -3.5184327e-01 */
    { 0x3f0bf929,0x3eff066f }, /* 296:  5.4677063e-01  4.9809596e-01 */
    { 0x3f0c2f05,0x3eff5765 }, /* 297:  5.4759246e-01  4.9871364e-01 */
    { 0xc0234c1f,0xbf7ce821 }, /* 298: -2.5515211e+00 -9.8791701e-01 */
    { 0xbf5b8f14,0xbf31ee88 }, /* 299: -8.5765195e-01 -6.9504595e-01 */
    { 0x3ed123d9,0x3ec63c40 }, /* 300:  4.0847662e-01  3.8717842e-01 */
    { 0x3f0f59b9,0x3f020900 }, /* 301:  5.5996281e-01  5.0794983e-01 */
    { 0x3f864258,0x3f480867 }, /* 302:  1.0488997e+00  7.8137821e-01 */
    { 0xbf703864,0xbf3c0619 }, /* 303: -9.3836045e-01 -7.3446804e-01 */
    { 0x3f3123fa,0x3f196792 }, /* 304:  6.9195521e-01  5.9923661e-01 */
    { 0xbe3c69c6,0xbe3a50ba }, /* 305: -1.8399724e-01 -1.8194857e-01 */
    { 0x3dcfb571,0x3dceffe0 }, /* 306:  1.0142029e-01  1.0107398e-01 */
    { 0xbf6190d0,0xbf34fc81 }, /* 307: -8.8111591e-01 -7.0697790e-01 */
    { 0xbef5a020,0xbee45e76 }, /* 308: -4.7973728e-01 -4.4603318e-01 */
    { 0xbed4490f,0xbec8e71f }, /* 309: -4.1461989e-01 -3.9238831e-01 */
    { 0xbef2ea91,0xbee23193 }, /* 310: -4.7444585e-01 -4.4178447e-01 */
    { 0xbfb33752,0xbf62a830 }, /* 311: -1.4001257e+00 -8.8537884e-01 */
    { 0x3efb1027,0x3ee8b441 }, /* 312:  4.9035761e-01  4.5450023e-01 */
    { 0x3eca559d,0x3ec06b9e }, /* 313:  3.9518443e-01  3.7582105e-01 */
    { 0xbe698939,0xbe6591d1 }, /* 314: -2.2806253e-01 -2.2418906e-01 */
    { 0x3ef64aed,0x3ee4e734 }, /* 315:  4.8104039e-01  4.4707644e-01 */
    { 0x3fc6466b,0x3f69e348 }, /* 316:  1.5490240e+00  9.1362429e-01 */
    { 0xbf424cc3,0xbf23f65e }, /* 317: -7.5898379e-01 -6.4047801e-01 */
    { 0x3edc9b94,0x3ecfe607 }, /* 318:  4.3087447e-01  4.0605184e-01 */
    { 0xbd0cb36f,0xbd0ca546 }, /* 319: -3.4350809e-02 -3.4337305e-02 */
    { 0x3eda54c1,0x3ecdfe6c }, /* 320:  4.2642787e-01  4.0233171e-01 */
    { 0xbf621b4f,0xbf3541ad }, /* 321: -8.8322920e-01 -7.0803338e-01 */
    { 0xbee2efe2,0xbed5285b }, /* 322: -4.4323641e-01 -4.1632351e-01 */
    { 0x3ecba845,0x3ec18e28 }, /* 323:  3.9776817e-01  3.7803769e-01 */
    { 0xbe66719f,0xbe62a17f }, /* 324: -2.2504281e-01 -2.2131918e-01 */
    { 0xbf26c2da,0xbf129727 }, /* 325: -6.5141070e-01 -5.7261890e-01 */
    { 0x3ef025c8,0x3edff5c4 }, /* 326:  4.6903825e-01  4.3742192e-01 */
    { 0x3ef2c0dc,0x3ee21001 }, /* 327:  4.7412765e-01  4.4152835e-01 */
    { 0x3e05dab7,0x3e0518de }, /* 328:  1.3071714e-01  1.2997767e-01 */
    { 0x3eba27c3,0x3eb25d3b }, /* 329:  3.6358461e-01  3.4836754e-01 */
    { 0x3ff9f4f5,0x3f75e5ab }, /* 330:  1.9527880e+00  9.6053571e-01 */
    { 0x41abefa6,0x3f800000 }, /* 331:  2.1492016e+01  1.0000000e+00 */
    { 0xbe996594,0xbe94f750 }, /* 332: -2.9960310e-01 -2.9094934e-01 */
    { 0x3ef27c12,0x3ee1d89c }, /* 333:  4.7360283e-01  4.4110572e-01 */
    { 0x3f3d1bb7,0x3f20dc4e }, /* 334:  7.3870414e-01  6.2836158e-01 */
    { 0x3edcf13a,0x3ed02d89 }, /* 335:  4.3152791e-01  4.0659741e-01 */
    { 0x3f47cc12,0x3f2728ff }, /* 336:  7.8045762e-01  6.5296930e-01 */
    { 0xbf30caa3,0xbf192e43 }, /* 337: -6.9059199e-01 -5.9836215e-01 */
    { 0x3f09ce5f,0x3efbc0a1 }, /* 338:  5.3830522e-01  4.9170402e-01 */
    { 0x3eb020db,0x3ea97ea5 }, /* 339:  3.4400067e-01  3.3104435e-01 */
    { 0xbf24055b,0xbf10bcc8 }, /* 340: -6.4070672e-01 -5.6538057e-01 */
    { 0xa92f441e,0xa92f441e }, /* 341: -3.8916888e-14 -3.8916888e-14 */
    { 0xbef2ad13,0xbee20013 }, /* 342: -4.7397670e-01 -4.4140682e-01 */
    { 0x3e84753f,0x3e819475 }, /* 343:  2.5870702e-01  2.5308576e-01 */
    { 0xbb7ac22b,0xbb7ac1db }, /* 344: -3.8262706e-03 -3.8262520e-03 */
    { 0x3ed01410,0x3ec55506 }, /* 345:  4.0640306e-01  3.8541430e-01 */
    { 0x3f7776b5,0x3f3f4a83 }, /* 346:  9.6665508e-01  7.4723071e-01 */
    { 0x3e54a87c,0x3e51a71c }, /* 347:  2.0767397e-01  2.0473903e-01 */
    { 0xbf322222,0xbf1a0a15 }, /* 348: -6.9583333e-01 -6.0171634e-01 */
    { 0x3f09a45e,0x3efb80e9 }, /* 349:  5.3766429e-01  4.9121788e-01 */
    { 0xbef3da4b,0xbee2f25b }, /* 350: -4.7627482e-01 -4.4325528e-01 */
    { 0xbeca76f9,0xbec08843 }, /* 351: -3.9543894e-01 -3.7603959e-01 */
    { 0xc37b3956,0xbf800000 }, /* 352: -2.5122397e+02 -1.0000000e+00 */
    { 0xbed9ea60,0xbecda53c }, /* 353: -4.2561626e-01 -4.0165126e-01 */
    { 0xc0f87e4c,0xbf7ffffa }, /* 354: -7.7654171e+00 -9.9999964e-01 */
    { 0xbef1cf3f,0xbee14d55 }, /* 355: -4.7228429e-01 -4.4004312e-01 */
    { 0x3dfc7356,0x3dfb2dfb }, /* 356:  1.2326686e-01  1.2264629e-01 */
    { 0x42283557,0x3f800000 }, /* 357:  4.2052090e+01  1.0000000e+00 */
    { 0xbdf42fe4,0xbdf30956 }, /* 358: -1.1923197e-01 -1.1867015e-01 */
    { 0xc2e38c3a,0xbf800000 }, /* 359: -1.1377388e+02 -1.0000000e+00 */
    { 0x40790bb1,0x3f7fc961 }, /* 360:  3.8913386e+00  9.9916655e-01 */
    { 0xbef1499f,0xbee0e189 }, /* 361: -4.7126481e-01 -4.3922070e-01 */
    { 0x3ecebd3f,0x3ec430d6 }, /* 362:  4.0378758e-01  3.8318509e-01 */
    { 0x3eefa0e8,0x3edf8a44 }, /* 363:  4.6802449e-01  4.3660176e-01 */
    { 0xbf08fb6e,0xbefa803d }, /* 364: -5.3508651e-01 -4.8925963e-01 */
    { 0x3f42f55c,0x3f2459a4 }, /* 365:  7.6155639e-01  6.4199281e-01 */
    { 0x3f303f9c,0x3f18d4e6 }, /* 366:  6.8847060e-01  5.9699857e-01 */
    { 0xbf0cd1c6,0xbf0025d2 }, /* 367: -5.5007589e-01 -5.0057709e-01 */
    { 0xbef7b477,0xbee6081f }, /* 368: -4.8379871e-01 -4.4928071e-01 */
    { 0x3e148673,0x3e137e0a }, /* 369:  1.4504413e-01  1.4403549e-01 */
    { 0x3f3313a6,0x3f1aa3d0 }, /* 370:  6.9951856e-01  6.0406208e-01 */
    { 0xc02dd35a,0xbf7dc52c }, /* 371: -2.7160249e+00 -9.9128985e-01 */
    { 0x3ff601a6,0x3f754472 }, /* 372:  1.9219253e+00  9.5807564e-01 */
    { 0x3f666678,0x3f375f55 }, /* 373:  9.0000105e-01  7.1629840e-01 */
    { 0x3ef36522,0x3ee2942e }, /* 374:  4.7538096e-01  4.4253677e-01 */
    { 0x3edf69b0,0x3ed23c66 }, /* 375:  4.3635321e-01  4.1061705e-01 */
    { 0x3df3a65c,0x3df281bd }, /* 376:  1.1896965e-01  1.1841152e-01 */
    { 0x3ef167fa,0x3ee0fa08 }, /* 377:  4.7149640e-01  4.3940759e-01 */
    { 0x3ed14cc6,0x3ec65f0a }, /* 378:  4.0878886e-01  3.8744384e-01 */
    { 0x3ea019f0,0x3e9b1454 }, /* 379:  3.1269789e-01  3.0288947e-01 */
    { 0xbef4db9c,0xbee3c0f0 }, /* 380: -4.7823799e-01 -4.4483137e-01 */
    { 0x3da00547,0x3d9fb21d }, /* 381:  7.8135066e-02  7.7976443e-02 */
    { 0x3f4dbcea,0x3f2a8439 }, /* 382:  8.0366385e-01  6.6608006e-01 */
    { 0xbf26900c,0xbf1274fd }, /* 383: -6.5063548e-01 -5.7209760e-01 */
    { 0xbef686e3,0xbee5172b }, /* 384: -4.8149785e-01 -4.4744238e-01 */
    { 0xbf0b548e,0xbefe0e97 }, /* 385: -5.4425895e-01 -4.9620506e-01 */
    { 0xbef3a857,0xbee2ca36 }, /* 386: -4.7589371e-01 -4.4294900e-01 */
    { 0x3f695162,0x3f38c80e }, /* 387:  9.1139805e-01  7.2180259e-01 */
    { 0x40ff6b39,0x3f7ffffc }, /* 388:  7.9818387e+00  9.9999976e-01 */
    { 0x3ed1c0a5,0x3ec6c17b }, /* 389:  4.0967289e-01  3.8819489e-01 */
    { 0x3f2ba88d,0x3f15d88a }, /* 390:  6.7054063e-01  5.8533537e-01 */
    { 0x3e9f90d4,0x3e9a97c2 }, /* 391:  3.1165183e-01  3.0193907e-01 */
    { 0x3f0c6c44,0x3effb361 }, /* 392:  5.4852700e-01  4.9941543e-01 */
    { 0xbf3ab3a3,0xbf1f6546 }, /* 393: -7.2930354e-01 -6.2263906e-01 */
    { 0xbeb52b22,0xbeadf7c0 }, /* 394: -3.5384470e-01 -3.3978081e-01 */
    { 0x3f325326,0x3f1a2957 }, /* 395:  6.9658124e-01  6.0219330e-01 */
    { 0xbf0d8523,0xbf00ac0e }, /* 396: -5.5281276e-01 -5.0262535e-01 */
    { 0xbebf2037,0xbeb6b774 }, /* 397: -3.7329265e-01 -3.5686839e-01 */
    { 0xbecb4f02,0xbec141a2 }, /* 398: -3.9708716e-01 -3.7745386e-01 */
    { 0x3fb3e735,0x3f62f3d9 }, /* 399:  1.4054934e+00  8.8653332e-01 */
    { 0x3ef906c2,0x3ee715d1 }, /* 400:  4.8637968e-01  4.5133832e-01 */
    { 0x3ebe7493,0x3eb6219b }, /* 401:  3.7198314e-01  3.5572514e-01 */
    { 0xbfdff6a2,0xbf70fbdb }, /* 402: -1.7497141e+00 -9.4134301e-01 */
    { 0x46e4b6dc,0x3f800000 }, /* 403:  2.9275430e+04  1.0000000e+00 */
    { 0x3f07739d,0x3ef82a72 }, /* 404:  5.2910787e-01  4.8469883e-01 */
    { 0xbf3a6634,0xbf1f35d3 }, /* 405: -7.2812200e-01 -6.2191504e-01 */
    { 0x3f264672,0x3f124372 }, /* 406:  6.4951241e-01  5.7134163e-01 */
    { 0xc62d4fef,0xbf800000 }, /* 407: -1.1091983e+04 -1.0000000e+00 */
    { 0x3f486be4,0x3f278487 }, /* 408:  7.8289628e-01  6.5436596e-01 */
    { 0x3df07e4b,0x3def64db }, /* 409:  1.1742838e-01  1.1689159e-01 */
    { 0xbea39f8f,0xbe9e4585 }, /* 410: -3.1957671e-01 -3.0912414e-01 */
    { 0x3f2d4548,0x3f16e6dd }, /* 411:  6.7683840e-01  5.8946019e-01 */
    { 0x3ef0f088,0x3ee0999c }, /* 412:  4.7058511e-01  4.3867195e-01 */
    { 0x3ec967d4,0x3ebf9f47 }, /* 413:  3.9337027e-01  3.7426206e-01 */
    { 0xbe9d1e85,0xbe985dbb }, /* 414: -3.0687347e-01 -2.9759011e-01 */
    { 0x3f2ab61a,0x3f1538d0 }, /* 415:  6.6684115e-01  5.8289814e-01 */
    { 0x3ebc494f,0x3eb43bdf }, /* 416:  3.6774680e-01  3.5201928e-01 */
    { 0xbf0defb8,0xbf00fba5 }, /* 417: -5.5443907e-01 -5.0383979e-01 */
    { 0xbee1371f,0xbed3bb7a }, /* 418: -4.3987367e-01 -4.1353971e-01 */
    { 0xbec1a3a3,0xbeb8e7f3 }, /* 419: -3.7820157e-01 -3.6114463e-01 */
    { 0xbf06fa73,0xbef770e2 }, /* 420: -5.2725905e-01 -4.8328310e-01 */
    { 0xbf0e3f9a,0xbf013737 }, /* 421: -5.5565798e-01 -5.0474876e-01 */
    { 0xbe9e96a1,0xbe99b43d }, /* 422: -3.0974296e-01 -3.0020323e-01 */
    { 0x3e6e91ba,0x3e6a5834 }, /* 423:  2.3297778e-01  2.2885209e-01 */
    { 0xbef397f5,0xbee2bd0b }, /* 424: -4.7576872e-01 -4.4284853e-01 */
    { 0xbef2f798,0xbee23c0f }, /* 425: -4.7454524e-01 -4.4186446e-01 */
    { 0x3f3013a5,0x3f18b898 }, /* 426:  6.8779975e-01  5.9656668e-01 */
    { 0x3ef4e5e6,0x3ee3c930 }, /* 427:  4.7831649e-01  4.4489431e-01 */
    { 0xbed4e16c,0xbec967f8 }, /* 428: -4.1578233e-01 -3.9337134e-01 */
    { 0xbf2614a6,0xbf1221e4 }, /* 429: -6.4875257e-01 -5.7082963e-01 */
    { 0x3ef635f2,0x3ee4d66a }, /* 430:  4.8088032e-01  4.4694835e-01 */
    { 0x3ff9574a,0x3f75cd28 }, /* 431:  1.9479764e+00  9.6016169e-01 */
    { 0xbef23a6f,0xbee1a3bc }, /* 432: -4.7310206e-01 -4.4070232e-01 */
    { 0xbf33ded5,0xbf1b249e }, /* 433: -7.0261890e-01 -6.0602748e-01 */
    { 0xbf464b24,0xbf264b57 }, /* 434: -7.7458405e-01 -6.4958709e-01 */
    { 0xbf148125,0xbf05d1f4 }, /* 435: -5.8009559e-01 -5.2273488e-01 */
    { 0xbed31829,0xbec7e4ef }, /* 436: -4.1229370e-01 -3.9041850e-01 */
    { 0x3ef37236,0x3ee29eb2 }, /* 437:  4.7548074e-01  4.4261700e-01 */
    { 0xbec98fbe,0xbebfc199 }, /* 438: -3.9367479e-01 -3.7452391e-01 */
    { 0xbec8ebcb,0xbebf3494 }, /* 439: -3.9242396e-01 -3.7344801e-01 */
    { 0x3ef0fa08,0x3ee0a148 }, /* 440:  4.7065759e-01  4.3873048e-01 */
    { 0x3e2793db,0x3e2618f1 }, /* 441:  1.6364996e-01  1.6220452e-01 */
    { 0xbf0d9972,0xbf00bb3b }, /* 442: -5.5312264e-01 -5.0285691e-01 */
    { 0xbe943850,0xbe9036b2 }, /* 443: -2.8949213e-01 -2.8166729e-01 */
    { 0xbed68487,0xbecac9c6 }, /* 444: -4.1897985e-01 -3.9607066e-01 */
    { 0xbecc7ef0,0xbec24608 }, /* 445: -3.9940596e-01 -3.7944055e-01 */
    { 0x3ffec6a6,0x3f769dd3 }, /* 446:  1.9904373e+00  9.6334571e-01 */
    { 0x3ec497b6,0x3ebb7809 }, /* 447:  3.8396996e-01  3.6615017e-01 */
    { 0xbf3d28a2,0xbf20e41f }, /* 448: -7.3890126e-01 -6.2848085e-01 */
    { 0x3e6654de,0x3e628626 }, /* 449:  2.2493312e-01  2.2121486e-01 */
    { 0x3e3ac549,0x3e38ba0a }, /* 450:  1.8239321e-01  1.8039718e-01 */
    { 0xbf43721a,0xbf24a2e1 }, /* 451: -7.6345980e-01 -6.4311033e-01 */
    { 0x3f0bc1d7,0x3efeb335 }, /* 452:  5.4592651e-01  4.9746099e-01 */
    { 0xbf3b0b76,0xbf1f9b02 }, /* 453: -7.3064363e-01 -6.2345898e-01 */
    { 0x405a8f59,0x3f7f727c }, /* 454:  3.4149992e+00  9.9784064e-01 */
    { 0x3f27b25e,0x3f1337cb }, /* 455:  6.5506542e-01  5.7507008e-01 */
    { 0xbef28355,0xbee1de76 }, /* 456: -4.7365823e-01 -4.4115037e-01 */
    { 0x3edb47c7,0x3ecec9f5 }, /* 457:  4.2828199e-01  4.0388456e-01 */
    { 0xbf0eef0e,0xbf01b9ca }, /* 458: -5.5833519e-01 -5.0674117e-01 */
    { 0x3ebbc499,0x3eb3c791 }, /* 459:  3.6673430e-01  3.5113195e-01 */
    { 0x3ef253ac,0x3ee1b812 }, /* 460:  4.7329462e-01  4.4085747e-01 */
    { 0x3f2ed3de,0x3f17ea06 }, /* 461:  6.8292034e-01  5.9341466e-01 */
    { 0xbebae31a,0xbeb301c1 }, /* 462: -3.6501390e-01 -3.4962276e-01 */
    { 0x3f0daade,0x3f00c83f }, /* 463:  5.5338848e-01  5.0305551e-01 */
    { 0x393b96c7,0x393b96c7 }, /* 464:  1.7889879e-04  1.7889879e-04 */
    { 0x3f0f8c42,0x3f022e7b }, /* 465:  5.6073391e-01  5.0852174e-01 */
    { 0xbf09f25b,0xbefbf72f }, /* 466: -5.3885430e-01 -4.9212024e-01 */
    { 0x3eb8cc5c,0x3eb12bb5 }, /* 467:  3.6093414e-01  3.4603658e-01 */
    { 0xbf12ccaa,0xbf0493a4 }, /* 468: -5.7343543e-01 -5.1787782e-01 */
    { 0xbf3383e4,0xbf1aeb07 }, /* 469: -7.0123124e-01 -6.0514873e-01 */
    { 0x3e96e927,0x3e92aff1 }, /* 470:  2.9474756e-01  2.8649858e-01 */
    { 0x3ef20f92,0x3ee18131 }, /* 471:  4.7277504e-01  4.4043878e-01 */
    { 0x3ef3ee55,0x3ee30275 }, /* 472:  4.7642770e-01  4.4337812e-01 */
    { 0xbeca6b41,0xbec07e33 }, /* 473: -3.9534953e-01 -3.7596282e-01 */
    { 0xbf0cc5b1,0xbf001cc4 }, /* 474: -5.4989153e-01 -5.0043893e-01 */
    { 0xbedb1785,0xbecea190 }, /* 475: -4.2791381e-01 -4.0357637e-01 */
    { 0x3f50df06,0x3f2c3ed6 }, /* 476:  8.1590307e-01  6.7283380e-01 */
    { 0x3f22555c,0x3f0f95c7 }, /* 477:  6.3411498e-01  5.6087917e-01 */
    { 0xbcfe2b24,0xbcfe1645 }, /* 478: -3.1026430e-02 -3.1016478e-02 */
    { 0xbf4a5c1c,0xbf289edd }, /* 479: -7.9046798e-01 -6.5867406e-01 */
    { 0xbf101e59,0xbf029aac }, /* 480: -5.6296307e-01 -5.1017261e-01 */
    { 0xbf0be01c,0xbefee0c1 }, /* 481: -5.4638839e-01 -4.9780849e-01 */
    { 0x3ef707fa,0x3ee57e5e }, /* 482:  4.8248273e-01  4.4822973e-01 */
    { 0x3edc86e0,0x3ecfd4bd }, /* 483:  4.3071651e-01  4.0591994e-01 */
    { 0x3ef60385,0x3ee4ae0e }, /* 484:  4.8049560e-01  4.4664043e-01 */
    { 0x3f070403,0x3ef77f8a }, /* 485:  5.2740496e-01  4.8339492e-01 */
    { 0xbf095f1c,0xbefb17c4 }, /* 486: -5.3660750e-01 -4.9041569e-01 */
    { 0xbef1ec5d,0xbee164cf }, /* 487: -4.7250643e-01 -4.4022223e-01 */
    { 0x5a14fb97,0x3f800000 }, /* 488:  1.0483731e+16  1.0000000e+00 */
    { 0xbf295b67,0xbf145335 }, /* 489: -6.6155094e-01 -5.7939464e-01 */
    { 0x3f2c5737,0x3f164b2f }, /* 490:  6.7320579e-01  5.8708471e-01 */
    { 0xbed7409e,0xbecb6845 }, /* 491: -4.2041487e-01 -3.9727989e-01 */
    { 0x3ef1be44,0x3ee13fa4 }, /* 492:  4.7215474e-01  4.3993866e-01 */
    { 0xbef1197a,0xbee0baac }, /* 493: -4.7089750e-01 -4.3892419e-01 */
    { 0xc217d302,0xbf800000 }, /* 494: -3.7956062e+01 -1.0000000e+00 */
    { 0x405f2d8b,0x3f7f857b }, /* 495:  3.4871547e+00  9.9813050e-01 */
    { 0xbf31992b,0xbf19b299 }, /* 496: -6.9374341e-01 -6.0038143e-01 */
    { 0xbef2b1fc,0xbee20407 }, /* 497: -4.7401416e-01 -4.4143698e-01 */
    { 0xbeccab47,0xbec26bfc }, /* 498: -3.9974424e-01 -3.7973011e-01 */
    { 0x3ef20330,0x3ee17736 }, /* 499:  4.7268057e-01  4.4036263e-01 */
    { 0xbef28e86,0xbee1e779 }, /* 500: -4.7374362e-01 -4.4121912e-01 */
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %#lx\n", index - 1, v.lo);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x, z;
    unsigned long v1, z1, r;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = tanh (x.fl);
	
	v1 = (v.lo < 0) ? (unsigned long)~(v.lo) : v.lo + 0x80000000;
	z1 = (z.lo < 0) ? (unsigned long)~(z.lo) : z.lo + 0x80000000;
	r = (v1 >= z1) ? v1 - z1 : z1 - v1;
	
	if (r > 4) x_exit (i+1);
    }
    return 0;
}
