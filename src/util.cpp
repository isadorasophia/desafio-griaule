
#include <cstring>
#include <iostream>

#include "3rd/GBSFingerprint.h"
#include "3rd/tinydir.h"

using namespace std;

void initializeSDK() {
	int ret = GrInitialize();

	if (ret < GR_OK) {
		cerr << "Unable to initialize Griaule Fingerprint SDK 2014." << endl;
		cerr << "For more information, check 'GBSFingerprint.h' file for the error code (" << ret << ")." << endl;
		exit(1);
	}
}


void loadImage(tinydir_file *file, GR_IMAGE **img) {
	int ret;
	char fullPath[_TINYDIR_PATH_MAX + _TINYDIR_FILENAME_MAX];

	strcpy(fullPath, file->path);

	if (file->is_dir) {
		strcat(fullPath, "/digital.png");
	}
	
	ret = GrLoadFromFile(fullPath, img);

	(*img)->resolution = 500;

	if (ret < GR_OK) {
		cerr << "Unable to load image from file '" << fullPath << "'." << endl;
		cerr << "For more information, check 'GBSFingerprint.h' file for the error code (" << ret << ")." << endl;
		exit(1);
	}
}

void extractTemplate(GR_IMAGE *img, GR_TEMPLATE **tpt) {
	int ret = GrExtract(img, DEFAULT, ASCII, tpt);

	if (ret < GR_OK) {
		cerr << "Unable to extract template from image.\n";
		cerr << "For more information, check 'GBSFingerprint.h' file for the error code (" << ret << ")." << endl;
		exit(1);
	}
}

bool matchTemplates(GR_TEMPLATE *query, GR_TEMPLATE *reference) {
	int ret, score;

	ret = GrVerify(query, reference, &score);

	if (ret < GR_OK) {
		cerr << "Unable to match templates." << endl;
		cerr << "For more information, check 'GBSFingerprint.h' file for the error code (" << ret << ")." << endl;
		exit(1);
	}

	return score > 5;
}

void finalizeSDK() {
	int ret = GrFinalize();

	if (ret < GR_OK) {
		cerr << "Unable to finalize Griaule Fingerprint SDK 2014." << endl;
		cerr << "For more information, check 'GBSFingerprint.h' file for the error code (" << ret << ")." << endl;
		exit(1);
	}
}

void openDir(tinydir_dir *dir, const char *path) {
	if (tinydir_open(dir, path) != 0) {
		cerr << "Unable to open directory '" << path << "'." << endl;
		cerr << "Please make sure the directory exists and is accessible." << endl;
		exit(1);
	}
}

void readFile(tinydir_dir *dir, tinydir_file *file) {
	if (tinydir_readfile(dir, file) != 0) {
		cerr << "Unable to open next file on direcory '" << dir->path << "'." << endl;
		exit(1);
	}
}
