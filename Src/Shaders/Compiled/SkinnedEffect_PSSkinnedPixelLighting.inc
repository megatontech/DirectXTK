#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xy          0     NONE   float   xy  
// TEXCOORD                 1   xyzw        1     NONE   float   xyzw
// TEXCOORD                 2   xyz         2     NONE   float   xyz 
// COLOR                    0   xyzw        3     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb0             0        14  ( FLT, FLT, FLT, FLT)
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    def c14, 1, 0, 0, 0
    dcl t0.xyz  // pin<0,1>
    dcl t1  // pin<2,3,4,5>
    dcl t2.xyz  // pin<6,7,8>
    dcl t3  // pin<9,10,11,12>
    dcl_2d s0

#line 233 "D:\Microsoft\DirectXTK\Src\Shaders\SkinnedEffect.fx"
    texld r0, t0, s0

#line 236
    nrm r1.xyz, t2  // ::worldNormal<0,1,2>

#line 36 "D:\Microsoft\DirectXTK\Src\Shaders\Lighting.fxh"
    dp3 r2.x, -c3, r1  // ::dotL<0>
    dp3 r2.y, -c4, r1  // ::dotL<1>
    dp3 r2.z, -c5, r1  // ::dotL<2>

#line 39
    cmp r3.xyz, r2, c14.x, c14.y  // ::zeroL<0,1,2>
    mul r2.xyz, r2, r3  // ::diffuse<0,1,2>

#line 235 "D:\Microsoft\DirectXTK\Src\Shaders\SkinnedEffect.fx"
    add r4.xyz, -t1, c12
    dp3 r1.w, r4, r4
    rsq r1.w, r1.w

#line 33 "D:\Microsoft\DirectXTK\Src\Shaders\Lighting.fxh"
    mad r5.xyz, r4, r1.w, -c3
    nrm r6.xyz, r5  // ::halfVectors<0,1,2>

#line 37
    dp3 r5.x, r6, r1  // ::dotH<0>

#line 33
    mad r6.xyz, r4, r1.w, -c4
    mad r4.xyz, r4, r1.w, -c5
    nrm r7.xyz, r4  // ::halfVectors<6,7,8>

#line 37
    dp3 r5.z, r7, r1  // ::dotH<2>

#line 33
    nrm r4.xyz, r6  // ::halfVectors<3,4,5>

#line 37
    dp3 r5.y, r4, r1  // ::dotH<1>

#line 42
    mul r1.xyz, r3, r5
    cmp r1.xyz, r5, r1, c14.y
    log r3.x, r1.x
    log r3.y, r1.y
    log r3.z, r1.z
    mul r1.xyz, r3, c2.w
    exp r2.w, r1.y  // ::specular<1>

#line 47
    mul r3.xyz, r2.w, c10

#line 42
    exp r2.w, r1.x  // ::specular<0>
    exp r3.w, r1.z  // ::specular<2>

#line 47
    mad r1.xyz, r2.w, c9, r3
    mad r1.xyz, r3.w, c11, r1
    mul r1.xyz, r1, c2  // ::result<3,4,5>

#line 233 "D:\Microsoft\DirectXTK\Src\Shaders\SkinnedEffect.fx"
    mul r0, r0, t3  // ::color<0,1,2,3>

#line 26 "D:\Microsoft\DirectXTK\Src\Shaders\Common.fxh"
    mul r1.xyz, r0.w, r1

#line 46 "D:\Microsoft\DirectXTK\Src\Shaders\Lighting.fxh"
    mul r3.xyz, r2.y, c7
    mad r3.xyz, r2.x, c6, r3
    mad r2.xyz, r2.z, c8, r3
    mov r3.xyz, c0  // Parameters::DiffuseColor<0,1,2>
    mad r2.xyz, r2, r3, c1  // ::result<0,1,2>

#line 26 "D:\Microsoft\DirectXTK\Src\Shaders\Common.fxh"
    mad r1.xyz, r0, r2, r1  // AddSpecular::color<0,1,2>

#line 20
    mad r2.xyz, c13, r0.w, -r1
    mad r0.xyz, t1.w, r2, r1  // ApplyFog::color<0,1,2>
    mov oC0, r0  // ::PSSkinnedPixelLighting<0,1,2,3>

// approximately 51 instruction slots used (1 texture, 50 arithmetic)
ps_4_0
dcl_constantbuffer CB0[14], immediateIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v0.xy
dcl_input_ps linear v1.xyzw
dcl_input_ps linear v2.xyz
dcl_input_ps linear v3.xyzw
dcl_output o0.xyzw
dcl_temps 4
add r0.xyz, -v1.xyzx, cb0[12].xyzx
dp3 r0.w, r0.xyzx, r0.xyzx
rsq r0.w, r0.w
mad r1.xyz, r0.xyzx, r0.wwww, -cb0[3].xyzx
dp3 r1.w, r1.xyzx, r1.xyzx
rsq r1.w, r1.w
mul r1.xyz, r1.wwww, r1.xyzx
dp3 r1.w, v2.xyzx, v2.xyzx
rsq r1.w, r1.w
mul r2.xyz, r1.wwww, v2.xyzx
dp3 r1.x, r1.xyzx, r2.xyzx
mad r3.xyz, r0.xyzx, r0.wwww, -cb0[4].xyzx
mad r0.xyz, r0.xyzx, r0.wwww, -cb0[5].xyzx
dp3 r0.w, r3.xyzx, r3.xyzx
rsq r0.w, r0.w
mul r3.xyz, r0.wwww, r3.xyzx
dp3 r1.y, r3.xyzx, r2.xyzx
dp3 r0.w, r0.xyzx, r0.xyzx
rsq r0.w, r0.w
mul r0.xyz, r0.wwww, r0.xyzx
dp3 r1.z, r0.xyzx, r2.xyzx
max r0.xyz, r1.xyzx, l(0.000000, 0.000000, 0.000000, 0.000000)
dp3 r1.x, -cb0[3].xyzx, r2.xyzx
dp3 r1.y, -cb0[4].xyzx, r2.xyzx
dp3 r1.z, -cb0[5].xyzx, r2.xyzx
ge r2.xyz, r1.xyzx, l(0.000000, 0.000000, 0.000000, 0.000000)
and r2.xyz, r2.xyzx, l(0x3f800000, 0x3f800000, 0x3f800000, 0)
mul r0.xyz, r0.xyzx, r2.xyzx
mul r1.xyz, r1.xyzx, r2.xyzx
log r0.xyz, r0.xyzx
mul r0.xyz, r0.xyzx, cb0[2].wwww
exp r0.xyz, r0.xyzx
mul r2.xyz, r0.yyyy, cb0[10].xyzx
mad r0.xyw, r0.xxxx, cb0[9].xyxz, r2.xyxz
mad r0.xyz, r0.zzzz, cb0[11].xyzx, r0.xywx
mul r0.xyz, r0.xyzx, cb0[2].xyzx
sample r2.xyzw, v0.xyxx, t0.xyzw, s0
mul r2.xyzw, r2.xyzw, v3.xyzw
mul r0.xyz, r0.xyzx, r2.wwww
mul r3.xyz, r1.yyyy, cb0[7].xyzx
mad r1.xyw, r1.xxxx, cb0[6].xyxz, r3.xyxz
mad r1.xyz, r1.zzzz, cb0[8].xyzx, r1.xywx
mad r1.xyz, r1.xyzx, cb0[0].xyzx, cb0[1].xyzx
mad r0.xyz, r2.xyzx, r1.xyzx, r0.xyzx
mad r1.xyz, cb0[13].xyzx, r2.wwww, -r0.xyzx
mad o0.xyz, v1.wwww, r1.xyzx, r0.xyzx
mov o0.w, r2.w
ret 
// Approximately 0 instruction slots used
#endif

const BYTE SkinnedEffect_PSSkinnedPixelLighting[] =
{
     68,  88,  66,  67, 105,  40, 
    224, 213, 125, 229,  69, 101, 
     47, 174,  10, 139,  35, 106, 
    106,  98,   1,   0,   0,   0, 
    216,  16,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
    208,   9,   0,   0,  36,  16, 
      0,   0, 164,  16,   0,   0, 
     65, 111, 110,  57, 152,   9, 
      0,   0, 152,   9,   0,   0, 
      0,   2, 255, 255, 100,   9, 
      0,   0,  52,   0,   0,   0, 
      1,   0,  40,   0,   0,   0, 
     52,   0,   0,   0,  52,   0, 
      1,   0,  36,   0,   0,   0, 
     52,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   2, 255, 255, 254, 255, 
    149,   1,  68,  66,  85,  71, 
     40,   0,   0,   0,  28,   6, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0, 188,   0, 
      0,   0,  49,   0,   0,   0, 
    200,   0,   0,   0,  14,   0, 
      0,   0,   4,   5,   0,   0, 
    132,   2,   0,   0,  68,  58, 
     92,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  92,  68, 
    105, 114, 101,  99, 116,  88, 
     84,  75,  92,  83, 114,  99, 
     92,  83, 104,  97, 100, 101, 
    114, 115,  92,  83, 107, 105, 
    110, 110, 101, 100,  69, 102, 
    102, 101,  99, 116,  46, 102, 
    120,   0,  68,  58,  92,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  92,  68, 105, 114, 
    101,  99, 116,  88,  84,  75, 
     92,  83, 114,  99,  92,  83, 
    104,  97, 100, 101, 114, 115, 
     92,  76, 105, 103, 104, 116, 
    105, 110, 103,  46, 102, 120, 
    104,   0,  68,  58,  92,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  92,  68, 105, 114, 
    101,  99, 116,  88,  84,  75, 
     92,  83, 114,  99,  92,  83, 
    104,  97, 100, 101, 114, 115, 
     92,  67, 111, 109, 109, 111, 
    110,  46, 102, 120, 104,   0, 
    171, 171,  40,   0,   0,   0, 
     92,   0,   0,   0, 140,   0, 
      0,   0,   0,   0, 255, 255, 
     92,   6,   0,   0,   0,   0, 
    255, 255, 116,   6,   0,   0, 
      0,   0, 255, 255, 128,   6, 
      0,   0,   0,   0, 255, 255, 
    140,   6,   0,   0,   0,   0, 
    255, 255, 152,   6,   0,   0, 
      0,   0, 255, 255, 164,   6, 
      0,   0, 233,   0,   0,   0, 
    176,   6,   0,   0, 236,   0, 
      0,   0, 192,   6,   0,   0, 
     36,   0,   1,   0, 204,   6, 
      0,   0,  36,   0,   1,   0, 
    220,   6,   0,   0,  36,   0, 
      1,   0, 236,   6,   0,   0, 
     39,   0,   1,   0, 252,   6, 
      0,   0,  41,   0,   1,   0, 
     16,   7,   0,   0, 235,   0, 
      0,   0,  32,   7,   0,   0, 
    235,   0,   0,   0,  48,   7, 
      0,   0, 235,   0,   0,   0, 
     64,   7,   0,   0,  33,   0, 
      1,   0,  76,   7,   0,   0, 
     33,   0,   1,   0,  96,   7, 
      0,   0,  37,   0,   1,   0, 
    108,   7,   0,   0,  33,   0, 
      1,   0, 124,   7,   0,   0, 
     33,   0,   1,   0, 144,   7, 
      0,   0,  33,   0,   1,   0, 
    164,   7,   0,   0,  37,   0, 
      1,   0, 176,   7,   0,   0, 
     33,   0,   1,   0, 192,   7, 
      0,   0,  37,   0,   1,   0, 
    204,   7,   0,   0,  42,   0, 
      1,   0, 220,   7,   0,   0, 
     42,   0,   1,   0, 236,   7, 
      0,   0,  42,   0,   1,   0, 
      0,   8,   0,   0,  42,   0, 
      1,   0,  12,   8,   0,   0, 
     42,   0,   1,   0,  24,   8, 
      0,   0,  42,   0,   1,   0, 
     36,   8,   0,   0,  42,   0, 
      1,   0,  52,   8,   0,   0, 
     47,   0,   1,   0,  64,   8, 
      0,   0,  42,   0,   1,   0, 
     80,   8,   0,   0,  42,   0, 
      1,   0,  92,   8,   0,   0, 
     47,   0,   1,   0, 104,   8, 
      0,   0,  47,   0,   1,   0, 
    124,   8,   0,   0,  47,   0, 
      1,   0, 144,   8,   0,   0, 
    233,   0,   0,   0, 160,   8, 
      0,   0,  26,   0,   2,   0, 
    176,   8,   0,   0,  46,   0, 
      1,   0, 192,   8,   0,   0, 
     46,   0,   1,   0, 208,   8, 
      0,   0,  46,   0,   1,   0, 
    228,   8,   0,   0,  46,   0, 
      1,   0, 248,   8,   0,   0, 
     46,   0,   1,   0,   4,   9, 
      0,   0,  26,   0,   2,   0, 
     24,   9,   0,   0,  20,   0, 
      2,   0,  44,   9,   0,   0, 
     20,   0,   2,   0,  64,   9, 
      0,   0,  20,   0,   2,   0, 
     84,   9,   0,   0,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114, 115,   0,  68, 105, 102, 
    102, 117, 115, 101,  67, 111, 
    108, 111, 114,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  43,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,  80,  83,  83, 107, 
    105, 110, 110, 101, 100,  80, 
    105, 120, 101, 108,  76, 105, 
    103, 104, 116, 105, 110, 103, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     48,   0,   0,   0,   0,   0, 
      1,   0,   2,   0,   3,   0, 
     65, 112, 112, 108, 121,  70, 
    111, 103,   0,  99, 111, 108, 
    111, 114,   0, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  47,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,  65, 100, 100,  83, 
    112, 101,  99, 117, 108,  97, 
    114,   0,  45,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,  38,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0, 100, 105, 102, 102, 
    117, 115, 101,   0,   1,   0, 
      3,   0,   1,   0,   3,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255, 100, 111, 116,  72, 
      0, 171, 171, 171,  18,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,  22,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0, 255, 255,  24,   0, 
      0,   0, 255, 255,   1,   0, 
    255, 255, 255, 255, 100, 111, 
    116,  76,   0, 171, 171, 171, 
      8,   0,   0,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      9,   0,   0,   0, 255, 255, 
      1,   0, 255, 255, 255, 255, 
     10,   0,   0,   0, 255, 255, 
    255, 255,   2,   0, 255, 255, 
    104,  97, 108, 102,  86, 101, 
     99, 116, 111, 114, 115,   0, 
      3,   0,   3,   0,   3,   0, 
      3,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  17,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255,  21,   0, 
      0,   0,   6,   0,   7,   0, 
      8,   0, 255, 255,  23,   0, 
      0,   0,   3,   0,   4,   0, 
      5,   0, 255, 255, 112, 105, 
    110,   0,  84, 101, 120,  67, 
    111, 111, 114, 100,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   2,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     80, 111, 115, 105, 116, 105, 
    111, 110,  87,  83,   0,  78, 
    111, 114, 109,  97, 108,  87, 
     83,   0,  68, 105, 102, 102, 
    117, 115, 101,   0, 200,   3, 
      0,   0, 212,   3,   0,   0, 
    228,   3,   0,   0, 200,   2, 
      0,   0, 239,   3,   0,   0, 
     16,   3,   0,   0, 248,   3, 
      0,   0, 200,   2,   0,   0, 
      5,   0,   0,   0,   1,   0, 
     13,   0,   1,   0,   4,   0, 
      0,   4,   0,   0,   1,   0, 
      0,   0,   0,   0,   1,   0, 
    255, 255, 255, 255,   2,   0, 
      0,   0,   2,   0,   3,   0, 
      4,   0,   5,   0,   3,   0, 
      0,   0,   6,   0,   7,   0, 
      8,   0, 255, 255,   4,   0, 
      0,   0,   9,   0,  10,   0, 
     11,   0,  12,   0, 114, 101, 
    115, 117, 108, 116,   0,  83, 
    112, 101,  99, 117, 108,  97, 
    114,   0, 248,   3,   0,   0, 
     16,   3,   0,   0, 103,   4, 
      0,   0,  16,   3,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      6,   0,   1,   0,   2,   0, 
    112,   4,   0,   0,  37,   0, 
      0,   0,   3,   0,   4,   0, 
      5,   0, 255, 255,  44,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255, 115, 112, 
    101,  99, 117, 108,  97, 114, 
      0, 171, 171, 171,  31,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   1,   0,  33,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   0,   0,  34,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   2,   0, 119, 111, 
    114, 108, 100,  78, 111, 114, 
    109,  97, 108,   0,   7,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255, 122, 101, 
    114, 111,  76,   0, 171, 171, 
     11,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
     80,   2,   0,   0,  91,   2, 
      0,   0, 104,   2,   0,   0, 
      1,   0,   0,   0, 120,   2, 
      0,   0,   0,   0,   0,   0, 
    132,   2,   0,   0, 156,   2, 
      0,   0,   1,   0,   0,   0, 
    172,   2,   0,   0, 184,   2, 
      0,   0, 193,   2,   0,   0, 
    200,   2,   0,   0,   1,   0, 
      0,   0, 216,   2,   0,   0, 
    228,   2,   0,   0, 193,   2, 
      0,   0, 200,   2,   0,   0, 
      1,   0,   0,   0, 240,   2, 
      0,   0,   0,   0,   0,   0, 
    193,   2,   0,   0, 200,   2, 
      0,   0,   1,   0,   0,   0, 
    252,   2,   0,   0,   0,   0, 
      0,   0,   8,   3,   0,   0, 
     16,   3,   0,   0,   1,   0, 
      0,   0,  32,   3,   0,   0, 
      0,   0,   0,   0,  44,   3, 
      0,   0,  16,   3,   0,   0, 
      3,   0,   0,   0,  52,   3, 
      0,   0,   0,   0,   0,   0, 
     88,   3,   0,   0,  16,   3, 
      0,   0,   3,   0,   0,   0, 
     96,   3,   0,   0,   0,   0, 
      0,   0, 132,   3,   0,   0, 
    144,   3,   0,   0,   3,   0, 
      0,   0, 160,   3,   0,   0, 
    132,   2,   0,   0, 196,   3, 
      0,   0,  32,   4,   0,   0, 
      4,   0,   0,   0,  48,   4, 
      0,   0,   0,   0,   0,   0, 
     96,   4,   0,   0, 128,   4, 
      0,   0,   2,   0,   0,   0, 
    144,   4,   0,   0,   0,   0, 
      0,   0, 168,   4,   0,   0, 
     16,   3,   0,   0,   3,   0, 
      0,   0, 180,   4,   0,   0, 
      0,   0,   0,   0, 216,   4, 
      0,   0,  16,   3,   0,   0, 
      1,   0,   0,   0, 228,   4, 
      0,   0,   0,   0,   0,   0, 
    240,   4,   0,   0,  16,   3, 
      0,   0,   1,   0,   0,   0, 
    248,   4,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     48,  46,  49,  48,  48,  49, 
     49,  46,  49,  54,  51,  56, 
     52,   0,  81,   0,   0,   5, 
     14,   0,  15, 160,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
      7, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   1,   0, 
     15, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   2,   0, 
      7, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   3,   0, 
     15, 176,  31,   0,   0,   2, 
      0,   0,   0, 144,   0,   8, 
     15, 160,  66,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 176,   0,   8, 228, 160, 
     36,   0,   0,   2,   1,   0, 
      7, 128,   2,   0, 228, 176, 
      8,   0,   0,   3,   2,   0, 
      1, 128,   3,   0, 228, 161, 
      1,   0, 228, 128,   8,   0, 
      0,   3,   2,   0,   2, 128, 
      4,   0, 228, 161,   1,   0, 
    228, 128,   8,   0,   0,   3, 
      2,   0,   4, 128,   5,   0, 
    228, 161,   1,   0, 228, 128, 
     88,   0,   0,   4,   3,   0, 
      7, 128,   2,   0, 228, 128, 
     14,   0,   0, 160,  14,   0, 
     85, 160,   5,   0,   0,   3, 
      2,   0,   7, 128,   2,   0, 
    228, 128,   3,   0, 228, 128, 
      2,   0,   0,   3,   4,   0, 
      7, 128,   1,   0, 228, 177, 
     12,   0, 228, 160,   8,   0, 
      0,   3,   1,   0,   8, 128, 
      4,   0, 228, 128,   4,   0, 
    228, 128,   7,   0,   0,   2, 
      1,   0,   8, 128,   1,   0, 
    255, 128,   4,   0,   0,   4, 
      5,   0,   7, 128,   4,   0, 
    228, 128,   1,   0, 255, 128, 
      3,   0, 228, 161,  36,   0, 
      0,   2,   6,   0,   7, 128, 
      5,   0, 228, 128,   8,   0, 
      0,   3,   5,   0,   1, 128, 
      6,   0, 228, 128,   1,   0, 
    228, 128,   4,   0,   0,   4, 
      6,   0,   7, 128,   4,   0, 
    228, 128,   1,   0, 255, 128, 
      4,   0, 228, 161,   4,   0, 
      0,   4,   4,   0,   7, 128, 
      4,   0, 228, 128,   1,   0, 
    255, 128,   5,   0, 228, 161, 
     36,   0,   0,   2,   7,   0, 
      7, 128,   4,   0, 228, 128, 
      8,   0,   0,   3,   5,   0, 
      4, 128,   7,   0, 228, 128, 
      1,   0, 228, 128,  36,   0, 
      0,   2,   4,   0,   7, 128, 
      6,   0, 228, 128,   8,   0, 
      0,   3,   5,   0,   2, 128, 
      4,   0, 228, 128,   1,   0, 
    228, 128,   5,   0,   0,   3, 
      1,   0,   7, 128,   3,   0, 
    228, 128,   5,   0, 228, 128, 
     88,   0,   0,   4,   1,   0, 
      7, 128,   5,   0, 228, 128, 
      1,   0, 228, 128,  14,   0, 
     85, 160,  15,   0,   0,   2, 
      3,   0,   1, 128,   1,   0, 
      0, 128,  15,   0,   0,   2, 
      3,   0,   2, 128,   1,   0, 
     85, 128,  15,   0,   0,   2, 
      3,   0,   4, 128,   1,   0, 
    170, 128,   5,   0,   0,   3, 
      1,   0,   7, 128,   3,   0, 
    228, 128,   2,   0, 255, 160, 
     14,   0,   0,   2,   2,   0, 
      8, 128,   1,   0,  85, 128, 
      5,   0,   0,   3,   3,   0, 
      7, 128,   2,   0, 255, 128, 
     10,   0, 228, 160,  14,   0, 
      0,   2,   2,   0,   8, 128, 
      1,   0,   0, 128,  14,   0, 
      0,   2,   3,   0,   8, 128, 
      1,   0, 170, 128,   4,   0, 
      0,   4,   1,   0,   7, 128, 
      2,   0, 255, 128,   9,   0, 
    228, 160,   3,   0, 228, 128, 
      4,   0,   0,   4,   1,   0, 
      7, 128,   3,   0, 255, 128, 
     11,   0, 228, 160,   1,   0, 
    228, 128,   5,   0,   0,   3, 
      1,   0,   7, 128,   1,   0, 
    228, 128,   2,   0, 228, 160, 
      5,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      3,   0, 228, 176,   5,   0, 
      0,   3,   1,   0,   7, 128, 
      0,   0, 255, 128,   1,   0, 
    228, 128,   5,   0,   0,   3, 
      3,   0,   7, 128,   2,   0, 
     85, 128,   7,   0, 228, 160, 
      4,   0,   0,   4,   3,   0, 
      7, 128,   2,   0,   0, 128, 
      6,   0, 228, 160,   3,   0, 
    228, 128,   4,   0,   0,   4, 
      2,   0,   7, 128,   2,   0, 
    170, 128,   8,   0, 228, 160, 
      3,   0, 228, 128,   1,   0, 
      0,   2,   3,   0,   7, 128, 
      0,   0, 228, 160,   4,   0, 
      0,   4,   2,   0,   7, 128, 
      2,   0, 228, 128,   3,   0, 
    228, 128,   1,   0, 228, 160, 
      4,   0,   0,   4,   1,   0, 
      7, 128,   0,   0, 228, 128, 
      2,   0, 228, 128,   1,   0, 
    228, 128,   4,   0,   0,   4, 
      2,   0,   7, 128,  13,   0, 
    228, 160,   0,   0, 255, 128, 
      1,   0, 228, 129,   4,   0, 
      0,   4,   0,   0,   7, 128, 
      1,   0, 255, 176,   2,   0, 
    228, 128,   1,   0, 228, 128, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   0,   0, 228, 128, 
    255, 255,   0,   0,  83,  72, 
     68,  82,  76,   6,   0,   0, 
     64,   0,   0,   0, 147,   1, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  14,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      0,   0,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3, 114,  16,  16,   0, 
      2,   0,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      3,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   4,   0,   0,   0, 
      0,   0,   0,   9, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,  12,   0,   0,   0, 
     16,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  68,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  11, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     68,   0,   0,   5, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   1,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     16,   0,   0,   7, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  18,  16,   0,   2,   0, 
      0,   0,  70,  18,  16,   0, 
      2,   0,   0,   0,  68,   0, 
      0,   5, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   2,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  70,  18,  16,   0, 
      2,   0,   0,   0,  16,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  11, 
    114,   0,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,  50,   0, 
      0,  11, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70, 130,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     16,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  68,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   3,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  16,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     68,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   0,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     16,   0,   0,   7,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  52,   0, 
      0,  10, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   9, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  70, 130,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  16,   0,   0,   9, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  70, 130,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  16,   0,   0,   9, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  70, 130,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  29,   0,   0,  10, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,  10, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     47,   0,   0,   5, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0, 246, 143, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  25,   0, 
      0,   5, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   5,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,  10,   0, 
      0,   0,  50,   0,   0,  10, 
    178,   0,  16,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70, 136, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  70,   8, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 114,   0, 
     16,   0,   0,   0,   0,   0, 
    166,  10,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,  70,   3,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   8, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  16,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  30,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   8, 
    114,   0,  16,   0,   3,   0, 
      0,   0,  86,   5,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,  50,   0, 
      0,  10, 178,   0,  16,   0, 
      1,   0,   0,   0,   6,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 136,  32,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     70,   8,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  10, 
    114,   0,  16,   0,   1,   0, 
      0,   0, 166,  10,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  70,   3, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  11, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,   9, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  11, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,  13,   0, 
      0,   0, 246,  15,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9, 114,  32,  16,   0, 
      0,   0,   0,   0, 246,  31, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 130,  32,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     62,   0,   0,   1,  73,  83, 
     71,  78, 120,   0,   0,   0, 
      4,   0,   0,   0,   8,   0, 
      0,   0, 104,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   3, 
      0,   0, 104,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,  15, 
      0,   0, 104,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   7,   7, 
      0,   0, 113,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,  15,  15, 
      0,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  67, 
     79,  76,  79,  82,   0, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  97, 114, 103, 101, 
    116,   0, 171, 171
};
