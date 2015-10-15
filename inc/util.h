
#include "3rd/GBSFingerprint.h"
#include "3rd/tinydir.h"

void initializeSDK();

void loadImage(tinydir_file *path, GR_IMAGE **img);

void extractTemplate(GR_IMAGE *img, GR_TEMPLATE **tpt);

bool matchTemplates(GR_TEMPLATE *query, GR_TEMPLATE *reference);

void finalizeSDK();

void openDir(tinydir_dir *dir, const char *path);

void readFile(tinydir_dir *dir, tinydir_file *file);