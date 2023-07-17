#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct HexCode 
{
    uint32_t value : 24; /* Use bit-field to take up as little memory as possible */
};

struct HexCode HexAverage(const struct HexCode HexCodeOne, const struct HexCode HexCodeTwo) 
{
    struct HexCode ResultHexCode;
    ResultHexCode.value = (HexCodeOne.value + HexCodeTwo.value) / 2;
    return ResultHexCode;
}

void RGBAverage(uint8_t RGBCodeAverage[3], const uint8_t RGBCodeOne[3], const uint8_t RGBCodeTwo[3]) 
{
    for (int i = 0; i < 3; i++) 
    {
        RGBCodeAverage[i] = (RGBCodeOne[i] + RGBCodeTwo[i]) / 2;
    }
}

void HSLAverage(uint8_t HSLCodeAverage[3], const uint8_t HSLCodeOne[3], const uint8_t HSLCodeTwo[3]) 
{
    /* Calculate average hue */
    int16_t delta = HSLCodeTwo[0] - HSLCodeOne[0];
    if (delta > 180) 
    {
        HSLCodeAverage[0] = HSLCodeOne[0] + delta / 2;
    }
    else if (delta < -180) 
    {
        HSLCodeAverage[0] = HSLCodeTwo[0] + (-delta) / 2;
    }
    else 
    {
        HSLCodeAverage[0] = (HSLCodeOne[0] + HSLCodeTwo[0]) / 2;
    }

    /* Calculate average saturation and lightness */
    HSLCodeAverage[1] = (HSLCodeOne[1] + HSLCodeTwo[1]) / 2;
    HSLCodeAverage[2] = (HSLCodeOne[2] + HSLCodeTwo[2]) / 2;
}

int main(int argc, const char* argv[]) 
{
    if (argc >= 3) 
    {
        for (int i = 1; i < argc; i++) 
        {
            if (strcmp(argv[i], "-hc") == 0 || strcmp(argv[i], "--hex") == 0) 
            {
                if (i + 2 < argc) {
                    struct HexCode HexCodeOne;
                    struct HexCode HexCodeTwo;

                    HexCodeOne.value = (uint32_t)strtol(argv[i + 1], NULL, 16);
                    HexCodeTwo.value = (uint32_t)strtol(argv[i + 2], NULL, 16);

                    struct HexCode AverageHexCode = HexAverage(HexCodeOne, HexCodeTwo);

                    printf("Average Hex Code: %06X\n", AverageHexCode.value);

                    i += 2;
                }
                else 
                {
                    fprintf(stderr, "Insufficient arguments for -hc or --hex option\n");
                }
            }
            else if (strcmp(argv[i], "-rgb") == 0)
            {
                if (i + 6 < argc) 
                {
                    uint8_t RgbCodeOne[3] = 
                    {
                        (uint8_t)atoi(argv[i + 1]),
                        (uint8_t)atoi(argv[i + 2]),
                        (uint8_t)atoi(argv[i + 3])
                    };
                    uint8_t RgbCodeTwo[3] = 
                    {
                        (uint8_t)atoi(argv[i + 4]),
                        (uint8_t)atoi(argv[i + 5]),
                        (uint8_t)atoi(argv[i + 6])
                    };
                    uint8_t RgbCodeAverage[3];

                    RGBAverage(RgbCodeAverage, RgbCodeOne, RgbCodeTwo);

                    printf("Average RGB Code: rgb(");
                    for (size_t i = 0; i < 3; i++) 
                    {
                        printf(" %u,", RgbCodeAverage[i]);
                    }
                    printf(")\n");

                    i += 6;
                }
                else 
                {
                    fprintf(stderr, "Insufficient arguments for -rgb option\n");
                }
            }
            else if (strcmp(argv[i], "-hsl") == 0)
            {
                if (i + 6 < argc) 
                {
                    uint8_t HSLCodeOne[3] = 
                    {
                        (uint8_t)atoi(argv[i + 1]),
                        (uint8_t)atoi(argv[i + 2]),
                        (uint8_t)atoi(argv[i + 3])
                    };
                    uint8_t HSLCodeTwo[3] = 
                    {
                        (uint8_t)atoi(argv[i + 4]),
                        (uint8_t)atoi(argv[i + 5]),
                        (uint8_t)atoi(argv[i + 6])
                    };
                    uint8_t HSLCodeAverage[3];

                    HSLAverage(HSLCodeAverage, HSLCodeOne, HSLCodeTwo);

                    printf("Average HSL Code: hsl(");
                    for (size_t i = 0; i < 3; i++) 
                    {
                        printf(" %u,", HSLCodeAverage[i]);
                    }
                    printf(")\n");

                    i += 6;
                }
                else 
                {
                    fprintf(stderr, "Insufficient arguments for -hsl option\n");
                }
            }
        }
    }
    else 
    {
        fprintf(stderr, "Usage: %s [-hc|--hex <hex_val1> <hex_val2>] [-rgb <r1> <g1> <b1> <r2> <g2> <b2>] [-hsl <h1> <s1> <l1> <h2> <s2> <l2>]\n", argv[0]);
    }
    return 0;
}