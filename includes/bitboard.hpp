# pragma once

# include <cstdint>
# include <x86intrin.h>

#define SquareOf(X) _tzcnt_u64(X)
#define ToMask(X) (1ull << (X))
#define Bitloop(X, var) for(auto var = X; var; var = __blsr_u64(var))
#define Flip(X) ((X) ^ 56)
#define FlipIf(cond, X) ((cond) ? ((X) ^ 56) : (X))

using Square = uint8_t;

const Square A1=0, B1=1, C1=2, D1=3, E1=4, F1=5, G1=6, H1=7;
const Square A2=8, B2=9, C2=10, D2=11, E2=12, F2=13, G2=14, H2=15;
const Square A3=16, B3=17, C3=18, D3=19, E3=20, F3=21, G3=22, H3=23;
const Square A4=24, B4=25, C4=26, D4=27, E4=28, F4=29, G4=30, H4=31;
const Square A5=32, B5=33, C5=34, D5=35, E5=36, F5=37, G5=38, H5=39;
const Square A6=40, B6=41, C6=42, D6=43, E6=44, F6=45, G6=46, H6=47;
const Square A7=48, B7=49, C7=50, D7=51, E7=52, F7=53, G7=54, H7=55;
const Square A8=56, B8=57, C8=58, D8=59, E8=60, F8=61, G8=62, H8=63;


using BitMask = uint64_t;

const BitMask A_FILE = 0x0101010101010101ull;
const BitMask B_FILE = 0x0202020202020202ull;
const BitMask C_FILE = 0x0404040404040404ull;
const BitMask D_FILE = 0x0808080808080808ull;
const BitMask E_FILE = 0x1010101010101010ull;
const BitMask F_FILE = 0x2020202020202020ull;
const BitMask G_FILE = 0x4040404040404040ull;
const BitMask H_FILE = 0x8080808080808080ull;

const BitMask RANK_1 = 0x00000000000000ffull;
const BitMask RANK_2 = 0x000000000000ff00ull;
const BitMask RANK_3 = 0x0000000000ff0000ull;
const BitMask RANK_4 = 0x00000000ff000000ull;
const BitMask RANK_5 = 0x000000ff00000000ull;
const BitMask RANK_6 = 0x0000ff0000000000ull;
const BitMask RANK_7 = 0x00ff000000000000ull;
const BitMask RANK_8 = 0xff00000000000000ull;

const BitMask CENTER = 0x0000001818000000ull;
const BitMask MIDDLE = 0x00003c3c3c3c0000ull;
const BitMask EDGES = 0xff818181818181ffull;
const BitMask CORNERS = 0x8100000000000081ull;

const BitMask LIGHT_SQUARES = 0x55aa55aa55aa55aaull;
const BitMask DARK_SQUARES = 0xaa55aa55aa55aa55ull;

const BitMask FULL_BOARD = 0xffffffffffffffffull;
const BitMask EMPTY_BOARD = 0ull;
