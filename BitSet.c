#include <stdio.h>
 
typedef unsigned short bitSet;
 
bitSet makeBitSet();
void displayBitSet(bitSet bs);
void setBit(bitSet* bs, int index);
void clearBit(bitSet* bs, int index);
int bitValue(bitSet bs, int index);
 
int main () {
    bitSet bits = makeBitSet();
    
    printf("BitSet\n");
    displayBitSet(bits);
    printf("Set a bit at index\n");
    setBit(&bits, 15);
    setBit(&bits, 13);
    displayBitSet(bits);
    printf("clear a bit at index\n");
    clearBit(&bits, 13);
    clearBit(&bits, 4);
    displayBitSet(bits);
    printf("bitValue at specified index(in this case index 15)\n");
    int value = bitValue(bits, 15);
    printf("%d\n", value);

}
 
// create a bitset
bitSet makeBitSet() {
    bitSet bits = 16;
    return bits;
}
 
// displays the 16 bits of the bitset
void displayBitSet(bitSet bs) {
  bitSet mask = 32768; // 2^15 == 1000 0000 0000 0000
  //for (int i = 0; i < 16; i++) {
  while(mask > 0){
    if((bs & mask) == 0) printf("0");
    else printf("1");
    mask = mask >> 1;
     }
    printf("\n");
}
 
// sets bit on the index of the bitset to 1
void setBit(bitSet* bs, int index) {
  bitSet mask = 1; //first bit 2^0
  mask = mask << index; // shift left to designated index
  *bs = *bs | mask; // or the operation to get new bitset
}
 
// sets bit index of the bitset to 0 
void clearBit(bitSet* bs, int index) {
  bitSet mask = 1; // first bit 2^0
  mask = mask << index; // shift left to designated index
   // Changes the number at index to 0
    *bs = *bs & ~mask;
}
 
// Returns the value of the bit at index
int bitValue(bitSet bs, int index){
    int value = (bs >> index) & 1U;
    
    return value;
}
