//
// Created by wei on 9/30/18.
//

#include "AVLTreeMap.h"

int main(int argc, char **argv) {

    char *strs[7] = {"E", "C", "H", "B", "D", "G", "I"};

    Map map = initMap_AVLMap();

    for (int i = 0; i < 7; ++i) {
        add_AVLMap(map, strs[i], i + 1);
    }
    set_AVLMap(map, strs[2], 1000);
    printf("%d\n", get_AVLMap(map, strs[2]));
    return 0;
}

