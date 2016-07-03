#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structures */
struct C_Verb {
    unsigned char Sequence:4;
    unsigned char DefAssociation:4;
};

struct D_Verb {
    unsigned char Misc:4;
    unsigned char Color:4;
};

struct E_Verb {
    unsigned char ConnType:4;
    unsigned char DefDev:4;
};

struct F_Verb {
    unsigned char LocPart2:4;
    unsigned char LocPart1:2;
    unsigned char PortConn:2;
};

/* 71dXX */
const char *Misc_Jack_Strings[16] = {
	"Jack Detect",
	"Jack Detect Ignore",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

const char *Misc_Color_Strings[16] = {
	"Unknown",
	"Black",
	"Grey",
	"Blue",
	"Green",
	"Red",
	"Orange",
	"Yellow",
	"Purple",
	"Pink",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"White",
	"Other"
}; 

/* 71eXX */
const char *ConnType_Strings[16] = {
    "Unknown",
    "1/8\" Stereo/Mono",
    "1/4\" Stereo/Mono",
    "ATAPI internal",
    "RCA",
    "Optical",
    "Other Digital",
    "Other Analog",
    "Multichannel Analog (DIN)",
    "XLR/Professional",
    "RJ11",
    "Combination",
    "Reserved",
    "Reserved",
    "Other"
};

const char *DefDev_Strings[16] = {
    "Line Out",
    "Speaker",
    "HP Out",
    "CD",
    "SPDIF Out",
    "Digital Other Out",
    "Modem Line Side",
    "Modem Handset Side",
    "Line In",
    "AUX",
    "Mic In",
    "Telephony",
    "SPDIF In",
    "Digital Other In",
    "Reserved",
    "Other"
};

/* 71fXX */
const char *PortConn_Strings[4] = {
    "Port Is Connected To A Jack",
    "No External Port -Or- No physical Connection For Port",
    "Fixed Function/Built In Device (Integrated Speaker, Mic, Etc)",
    "Jack And Internal Device Are Attached"
};

const char *LocPart1_Strings[4] = {
    "External On Primary Chassis",
    "Internal",
    "Separate Chassis",
    "Other"
};

const char *LocPart2_Strings_0[16] = {
    "Not Attached",
    "Rear",
    "Front",
    "Left",
    "Right",
    "Top",
    "Bottom",
    "Special (Rear Panel)",
    "Special (Drive Bay)",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

const char *LocPart2_Strings_1[16] = {
    "N/A",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Special (Riser)",
    "HDMI",
    "ATAPI",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

const char *LocPart2_Strings_2[16] = {
    "N/A",
    "Rear",
    "Front",
    "Left",
    "Right",
    "Top",
    "Bottom",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

const char *LocPart2_Strings_3[16] = {
    "N/A",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "???",
    "Inside Mobile Lid (example: mic)",
    "Outside Mobile Lid",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void Parse_C_Verb(unsigned long *verb)
{
    struct C_Verb *verbconv = (struct C_Verb *)verb;

    printf("%.3X71C%.2X\n", (unsigned int)((verb[0] & 0xFFF00000) >> 20), (unsigned int)(verb[0] & 0xFF));
    printf("Codec Addres: %u\n", (unsigned int)((verb[0] & 0xF0000000) >> 28));
    printf("Node ID: %u\n", (unsigned int)((verb[0] & 0x0FF00000) >> 20));

    printf("Sequence: %u\n", verbconv->Sequence);
    printf("Default Association: %u\n\n", verbconv->DefAssociation);
}

void Parse_D_Verb(unsigned long *verb)
{
    struct D_Verb *verbconv = (struct D_Verb *)verb;

    printf("%.3X71D%.2X\n", (unsigned int)((verb[0] & 0xFFF00000) >> 20), (unsigned int)(verb[0] & 0xFF));
    printf("Codec Addres: %u\n", (unsigned int)((verb[0] & 0xF0000000) >> 28));
    printf("Node ID: %u\n", (unsigned int)((verb[0] & 0x0FF00000) >> 20));

    printf("Misc: %s\n", Misc_Jack_Strings[verbconv->Misc]);
    printf("Color: %s\n\n", Misc_Color_Strings[verbconv->Color]);
}

void Parse_E_Verb(unsigned long *verb)
{
    struct E_Verb *verbconv = (struct E_Verb *)verb;

    printf("%.3X71E%.2X\n", (unsigned int)((verb[0] & 0xFFF00000) >> 20), (unsigned int)(verb[0] & 0xFF));
    printf("Codec Addres: %u\n", (unsigned int)((verb[0] & 0xF0000000) >> 28));
    printf("Node ID: %u\n", (unsigned int)((verb[0] & 0x0FF00000) >> 20));

    printf("Connection Type: %s\n", ConnType_Strings[verbconv->ConnType]);
    printf("Default Device: %s\n\n", DefDev_Strings[verbconv->DefDev]);
}

void Parse_F_Verb(unsigned long *verb)
{
    struct F_Verb *verbconv = (struct F_Verb *)verb;

    printf("%.3X71F%.2X\n", (unsigned int)((verb[0] & 0xFFF00000) >> 20), (unsigned int)(verb[0] & 0xFF));
    printf("Codec Addres: %u\n", (unsigned int)((verb[0] & 0xF0000000) >> 28));
    printf("Node ID: %u\n", (unsigned int)((verb[0] & 0x0FF00000) >> 20));
           
    printf("Port Connectivity: %s\n", PortConn_Strings[verbconv->PortConn]);
    printf("Location Part 1: %s\n", LocPart1_Strings[verbconv->LocPart1]);

    switch(verbconv->LocPart1)
    {
        case 0:
            printf("Location Part 2: %s\n\n", LocPart2_Strings_0[verbconv->LocPart2]);
            break;

        case 1:
            printf("Location Part 2: %s\n\n", LocPart2_Strings_1[verbconv->LocPart2]);
            break;

        case 2:
            printf("Location Part 2: %s\n\n", LocPart2_Strings_2[verbconv->LocPart2]);
            break;

        case 3:
            printf("Location Part 2: %s\n\n", LocPart2_Strings_3[verbconv->LocPart2]);
            break;

        default:
            printf("Location Part 2: ERROR\n\n");
            break;
    }
}

char DetectVerbType(unsigned long verb)
{
    unsigned long verbid = (verb & 0xFFF00);

    switch (verbid)
    {
        case 0x71c00:
            return(1);

        case 0x71d00:
            return(2);

        case 0x71e00:
            return(3);

        case 0x71f00:
            return(4);
    }

    return(0);
}

char ConvChar(char input)
{
    switch (input)
    {
        case '0':
            return(0);

        case '1':
            return(1);

        case '2':
            return(2);

        case '3':
            return(3);

        case '4':
            return(4);

        case '5':
            return(5);
            
        case '6':
            return(6);
            
        case '7':
            return(7);
            
        case '8':
            return(8);
            
        case '9':
            return(9);
            
        case 'a':
        case 'A':
            return(10);
            
        case 'b':
        case 'B':
            return(11);
            
        case 'c':
        case 'C':
            return(12);
            
        case 'd':
        case 'D':
            return(13);
            
        case 'e':
        case 'E':
            return(14);
            
        case 'f':
        case 'F':
            return(15);
    }

    return(0xFF);
}

unsigned long GetVerb(char *input)
{
    unsigned long tmpval = 0;

    tmpval += (ConvChar(input[0]) << 28);
    tmpval += (ConvChar(input[1]) << 24);
    tmpval += (ConvChar(input[2]) << 20);
    tmpval += (ConvChar(input[3]) << 16);
    tmpval += (ConvChar(input[4]) << 12);
    tmpval += (ConvChar(input[5]) << 8);
    tmpval += (ConvChar(input[6]) << 4);
    tmpval += (ConvChar(input[7]));

    return(tmpval);
}

void Usage(char *name)
{
    printf("Usage: %s <inputfile_verbs>\n", name);
    printf("Copyright 2012 AnV Software\n");
}

int main(int argc, char **argv)
{
    FILE *f;
    char *buffer = NULL;
    char *verbchars = NULL;
    int filesize = 0;
    unsigned long verb = 0;
    int count = 0;

    if (argc != 2)
    {
        Usage(argv[0]);
        return(1);
    }

    f = fopen(argv[1], "rb");

    fseek(f,0,SEEK_END);
    filesize = ftell(f);
    fseek(f,0,SEEK_SET);

    buffer = malloc(filesize);
    verbchars = malloc(8);
    fread(buffer, filesize, 1, f);

    while(filesize > 0)
    {
        while((buffer[0] == 0x20) || (buffer[0] == 0x0A))
        {
            ++buffer;
            --filesize;
        }

        strncpy(verbchars, buffer, 8);
        verb = GetVerb(verbchars);

        if (DetectVerbType(verb) != 0)
        {
            ++count;

            printf("<= Verb %d =>\n", count);
        }

        switch(DetectVerbType(verb))
        {
            case 1:
                Parse_C_Verb(&verb);
                break;

            case 2:
                Parse_D_Verb(&verb);
                break;

            case 3:
                Parse_E_Verb(&verb);
                break;

            case 4:
                Parse_F_Verb(&verb);
                break;

            default:
                printf("bad verb (%u), 0x%X\n", DetectVerbType(verb), (unsigned int)verb);
                break;
        }

        if (DetectVerbType(verb) == 0)
        {
            ++buffer;
            --filesize;
        } else {
            buffer += 8;
            filesize -= 8;
        }
    }

    return(0);
}
