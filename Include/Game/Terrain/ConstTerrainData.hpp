#pragma once

const static int TERRAIN_CHUNK_SIZE{16};
const static int TERRAIN_TILE_SIZE{16};
const static int TERRAIN_SUB_TILE_SIZE{8};
const static int TERRAIN_SUB_TILE_COUNT{4};
const static int TERRAIN_CHUNK_SUB_TILE_COUNT{TERRAIN_CHUNK_SIZE*TERRAIN_CHUNK_SIZE*TERRAIN_SUB_TILE_COUNT};
