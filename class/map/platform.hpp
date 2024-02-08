#ifndef PLATFORM_H
#define PLATFORM_H


class platform {
    public:
    int platN, width;
    int x, y;
    platform (int x, int y, int platN, int width);

    static void platformType (platform *platf[], int randPlatType);
    static void shops_type (int rand_shop, platform* shop_layout[]);
};

#endif
