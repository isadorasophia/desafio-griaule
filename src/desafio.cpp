#include <iostream>
#include <string.h>

#include "3rd/GBSFingerprint.h"
#include "3rd/tinydir.h"
#include "util.h"

#define HELP_OPTION "--help"

using namespace std;

int main(int argc, char const *argv[]) {
	int ret;
	GR_IMAGE 	 *suspectImg, *dbImg;
	GR_TEMPLATE  *suspectTpt, *dbTpt;
	tinydir_dir  suspectsDir, dbDir;
	tinydir_file dbFile, suspectFile;
	char* productKey;

	if (argc != 3 || strcmp(argv[1], HELP_OPTION) == 0) {
		cerr << "Please call the executable as the following:" << endl;
		cerr << "\t./desafio-griaule <databaseDir> <suspectsDir>" << endl;
		exit(1);
	}

	initializeSDK();

	// is it a valid path?
	openDir(&dbDir, argv[1]);

	// Iterate through all database entries
	while (dbDir.has_next) {
		readFile(&dbDir, &dbFile);

		// Skip directories
		if (dbFile.is_dir) {
			// is there a next file?
			if (tinydir_next(&dbDir) != 0) {
				break;
			} else {
				continue;
			}
		}

		// Load files from disk
		loadImage(&dbFile, &dbImg);

		// Extract templates
		extractTemplate(dbImg, &dbTpt);

		openDir(&suspectsDir, argv[2]);

		// Iterate through all suspects
		while (suspectsDir.has_next) {
			readFile(&suspectsDir, &suspectFile);

			// Skip non-directories
			if (!suspectFile.is_dir || strcmp(suspectFile.name, ".") == 0 || strcmp(suspectFile.name, "..") == 0) {
				// is there a next file?
				if (tinydir_next(&suspectsDir) != 0) {
					break;
				} else {
					continue;
				}
			}

			// Load files from disk
			loadImage(&suspectFile, &suspectImg);

			cout << "Q" << endl;

			// Extract templates
			extractTemplate(suspectImg, &suspectTpt);
 
			// Match templates
			cout << "Matching '" << dbFile.name
				 << "' against '" << suspectFile.name
				 << "':";

			if (matchTemplates(suspectTpt, dbTpt)) {
				cout << " MATCH!" << endl;
			} else {
				cout << " NO MATCH!" << endl;
			}

			// free image files
			GrFreeImage(&suspectImg);

			// free templates
			GrFreeTemplate(&suspectTpt);

			if (tinydir_next(&suspectsDir) != 0) {
				break;
			}
		}

		// free image files
		GrFreeImage(&dbImg);

		// free templates
		GrFreeTemplate(&dbTpt);

		tinydir_close(&suspectsDir);

		if (tinydir_next(&dbDir) != 0) {
			break;
		}
	}

	tinydir_close(&dbDir);

	finalizeSDK();

	// free(productKey);

	return 0;
}