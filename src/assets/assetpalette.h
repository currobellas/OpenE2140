//
// Created by Ion Agorria on 29/04/18
//
#ifndef OPENE2140_ASSETPALETTE_H
#define OPENE2140_ASSETPALETTE_H

/** Size of each palette in color count */
#define PALETTE_COUNT 256

#include "asset.h"

/**
 * Palette information asset
 */
class AssetPalette : public Asset {
public:
    /**
     * Struct for each color
     */
    typedef struct {
        byte R;
        byte G;
        byte B;
    } Color;

    /**
     * Constructor for palette asset
     *
     * @param path where this asset is located
     * @param file to use when accessing data
     * @param fileOffset where asset data start in file
     * @param fileSize of asset data in file, 0 for unknown/until end
     */
    AssetPalette(const std::string& path, const std::shared_ptr<File> file, long fileOffset, long fileSize);

    /**
     * Gets the color value at index in this palette
     *
     * @param index to look
     * @param color struct to fill
     * @return 0 or less if error, color position if OK
     */
    long AssetPalette::getColor(int index, AssetPalette::Color& color);
};

#endif //OPENE2140_ASSETPALETTE_H
