#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

typedef uint32_t _DWORD;
typedef uint16_t _WORD;
typedef uint8_t _BYTE;


const char * off_40B0 = "dcrtinshzm";
const char * off_40AC = "dlbfikqm";

//byte_4049

const char *off_4060[] = {
"EKMFLGDQVZNTOWYHXUSPAIBRCJ",
"AJDKSIRUXBLHWTMCQGZNPYFVOE",
"BDFHJLCPRTXVZNYEIWGAKMUSQO",
"ESOVPZJAYQUIRHXLNFTGKDCMWB",
"VZBRGITYUPSDNHLXAWMJQOFECK",
"JPGVOUMFYQBENHZRDKASXLICTW",
"NZJHGRCXMYSWBOUFAIVLPEKQDT",
"FKQHTLXOCBJSPDZRAMEWNIUYGV",
"AJPCZWRLFBDKOTYUQGENHXMIVS",
"TAGBPCSDQEUFVNZHYIXJWLRKOM",
"HZWVARTNLGUPXQCEJMBSKDYOIF",
"QCYLXWENFTZOSMVJUDKGIARPHB",
"SKXQLHCNWARVGMEBJPTYFDZUIO",
"QMGYVPEDRCWTIANUXFKZOSLHJB",
"QJINSAYDVKBFRUHMCPLEWZTGXO",
"EJMZALYXVBWFCRQUONTSPIKHGD", // off_40A0
"YRUHQSLDPXNGOKMIEBFZCWVJAT",
"FVPJIAOYEDRZXWGCTKUQSBNMHL"
};

const char **off_40A0 = &off_4060[15];

const uint8_t byte_4048[] = "\x51\x51EEVVJJZZZMZMZM";
const uint8_t *byte_4049 = &byte_4048[1];



_DWORD * init_buffer(_DWORD *a1)
{
  _DWORD *result; // eax
  int i; // [esp+Ch] [ebp-4h]

  a1[4] = 0;
  a1[5] = 0;
  a1[6] = 0;
  a1[3] = 1;
  a1[7] = 0;
  a1[8] = 0;
  a1[9] = 0;
  for ( i = 0; i <= 12; ++i )
  {
    *((_BYTE *)a1 + 2 * i + 40) = -1;
    *((_BYTE *)a1 + 2 * i + 41) = -1;
  }
  *a1 = 0;
  a1[1] = 1;
  result = a1;
  a1[2] = 2;
  return result;
}

// =============================================

int  sub_160E(int *a1, int a2)
{
  int result; // eax

  if ( a1[1] + 65 == byte_4048[2 * *(_DWORD *)(a2 + 4)] || a1[1] + 65 == byte_4049[2 * *(_DWORD *)(a2 + 4)] )
  {
    *a1 = (*a1 + 1) % 26;
    a1[1] = (a1[1] + 1) % 26;
  }
  if ( a1[2] + 65 == byte_4048[2 * *(_DWORD *)(a2 + 8)] || a1[2] + 65 == byte_4049[2 * *(_DWORD *)(a2 + 8)] )
    a1[1] = (a1[1] + 1) % 26;
  result = (a1[2] + 1) % 26;
  a1[2] = result;
  return result;
}

int  sub_148A(uint8_t a1, int a2)
{
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i <= 12; ++i )
  {
    if ( a1 == *(_BYTE *)(2 * i + a2) )
      return *(uint8_t *)(2 * i + a2 + 1);
    if ( a1 == *(_BYTE *)(2 * i + a2 + 1) )
      return *(uint8_t *)(2 * i + a2);
  }
  return a1;
}

int  sub_1564(int a1, char a2, int a3)
{
  return ((off_4060)[a1][(a2 - 39 + a3) % 26] - a3 - 39) % 26 + 65;
}

int  sub_15E0(int a1, char a2)
{
  return (uint8_t)(off_40A0)[a1][a2 - 65];
}

int  sub_1501(int a1)
{
  int result; // eax

  switch ( a1 )
  {
    case 0:
      result = 8;
      break;
    case 1:
      result = 9;
      break;
    case 2:
      result = 10;
      break;
    case 3:
      result = 11;
      break;
    case 4:
      result = 12;
      break;
    case 5:
      result = 13;
      break;
    case 6:
      result = 14;
      break;
    case 7:
      result = 15;
      break;
    default:
      result = -1;
      break;
  }
  return result;
}

int  sub_12CA(char a1, _DWORD *ptr)
{
  char v2; // al
  char v3; // al
  char v4; // al
  char v5; // al
  char v6; // al
  int v7; // esi
  int v8; // ebx
  int v9; // eax
  char v10; // al
  int v11; // esi
  int v12; // ebx
  int v13; // eax
  char v14; // al
  int v15; // esi
  int v16; // ebx
  int v17; // eax
  char v18; // al
  char v20; // [esp+Ch] [ebp-Ch]

  v20 = toupper(a1);
  sub_160E(ptr + 4, ptr);
  v2 = sub_148A(v20, ptr + 10);
  v3 = sub_1564(ptr[2], v2, ptr[6] - ptr[9]);
  v4 = sub_1564(ptr[1], v3, ptr[5] - ptr[8]);
  v5 = sub_1564(*ptr, v4, ptr[4] - ptr[7]);
  v6 = sub_15E0(ptr[3], v5);
  v7 = ptr[4] - ptr[7];
  v8 = v6;
  v9 = sub_1501(*ptr);
  v10 = sub_1564(v9, v8, v7);
  v11 = ptr[5] - ptr[8];
  v12 = v10;
  v13 = sub_1501(ptr[1]);
  v14 = sub_1564(v13, v12, v11);
  v15 = ptr[6] - ptr[9];
  v16 = v14;
  v17 = sub_1501(ptr[2]);
  v18 = sub_1564(v17, v16, v15);
  return (uint8_t)sub_148A(v18, ptr + 10);
}

size_t  sub_124D(int ptr, char *s, int a3)
{
  char v3; // al
  size_t result; // eax
  size_t i; // [esp+Ch] [ebp-Ch]

  for ( i = 0; strlen(s) > i; ++i )
  {
    v3 = sub_12CA(s[i], ptr);
    *(_BYTE *)(i + a3) = tolower(v3);
  }
  result = i + a3;
  *(_BYTE *)(i + a3) = 0;
  return result;
}

void  sub_1AEA(char *s, int ptr)
{
  char *src; // [esp+Ch] [ebp-Ch]

  src = (char *)calloc(9u, 1u);
  sub_124D(ptr, off_40AC, (int)src);
  strcpy(&s[strlen(s)], "oren_ctf_");
  strcat(s, src);
  *(_WORD *)&s[strlen(s)] = 33;
  free(src);
}

// =============================================

int main()
{
  _DWORD *ptr; // [esp+0h] [ebp-18h]
  char *v2; // [esp+4h] [ebp-14h]
  char *s1; // [esp+8h] [ebp-10h]
  char *s; // [esp+Ch] [ebp-Ch]

  ptr = calloc(1u, 0x44u);
  v2 = (char *)calloc(0x12u, 1u);
  s1 = (char *)calloc(0xBu, 1u);
  s = (char *)calloc(0xBu, 1u);
  puts("Welcome to super-safety flag store!");
  puts("Try to decrypt flag...");
  puts("-------------------------------------------");
  init_buffer(ptr);

  puts("step 2");
  sub_1AEA(v2, (int)ptr);

  puts("step 3");
  sub_124D((int)ptr, off_40B0, (int)s1);

  puts(s1);
  puts(v2);

  puts("Success!\n");
  printf("Please enter password for see it: ");
  fgets(s, 11, stdin);
  if ( !strcmp(s1, s) )
    printf("\nCongrats!\nThats your flag: %s\n", v2);
  else
    puts("\nToo bad!");
  free(ptr);
  free(v2);
  free(s1);
  free(s);
  return 0;
}