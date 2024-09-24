#include <stdio.h>
#include "netpipes.h"

int32_t init_test_plane(item_type_t plane[TEST_PLANE_SIZE][TEST_PLANE_SIZE]) {
    for(uint16_t i = 0; i < TEST_PLANE_SIZE; i++) {
        for(uint16_t j = 0; j < TEST_PLANE_SIZE; j++) {
            plane[i][j] = AIR;
        }
    }

    plane[0][0] = SOURCE;
    plane[0][1] = PIPE;
    plane[0][2] = PIPE;
    plane[0][3] = SINK;
    plane[1][1] = PIPE;
    plane[2][1] = SINK;

    return 0;
}

int32_t print_test_plane(item_type_t plane[TEST_PLANE_SIZE][TEST_PLANE_SIZE]) {
    puts("*** Test Plane Printout ***");
    printf("⬜️");
    for(uint16_t i = 0; i < TEST_PLANE_SIZE; i++) {
        printf("⬜️");
    }
    puts("⬜️");

    for(uint16_t i = 0; i < TEST_PLANE_SIZE; i++) {
        printf("⬜️");
        for(uint16_t j = 0; j < TEST_PLANE_SIZE; j++) {
            item_type_t item_type = plane[i][j];
            char *its = item_type_to_str(item_type);
            if(its[0] == '\0') {
                fprintf(stderr, "unable to convert item_type (int value %d) to char at plane[%u,%u]\n", (int32_t) item_type, i, j);
                return 1;
            }
            printf(its);
        }
        puts("⬜️");
    }

    printf("⬜️");
    for(uint16_t i = 0; i < TEST_PLANE_SIZE; i++) {
        printf("⬜️");
    }
    puts("⬜️");

    return 0;
}

static int32_t _demo() {
    puts("netpipes demo");
    puts("=============");
    puts("");

    item_type_t plane[TEST_PLANE_SIZE][TEST_PLANE_SIZE];
    
    char tempbuf = 0;

    {
        int32_t error = init_test_plane(plane);
        if(error) {
            fprintf(stderr, "Unable to initialise test plane, errcode %d\n", error);
            return error;
        }
    }
    
    puts("Test plane done. Press enter to print.");
    scanf("%s", &tempbuf);

    {
        int32_t error = print_test_plane(plane);
        if(error) {
            fprintf(stderr, "Unable to print test plane, errcode %d\n", error);
            return error;
        }
    }

    puts("\nOk");
    return 0;
}

int32_t main() {
    int32_t error = _demo();
    if(error) {
        puts("\n+===============+");
        printf("| MALFUNCTION %d |\n", error);
        puts("+===============+");
    }
    return error;
}

