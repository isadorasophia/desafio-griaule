/******************************************************
 *                                                    *
 * GBS Fingerprint SDK                                *
 *                                                    *
 * GBSFingerprint.h                                   *
 * C++ Header file for GrFinger Library               *
 *                                                    *
 * Copyright (c) 2004-2015 Griaule Biometrics LTDA.   *
 *                                                    *
 * Last Modified: 2015-06-10 Revision: 4              *
 *                                                    *
 ******************************************************/

#ifndef IMPORTDLL_H
#define IMPORTDLL_H

#ifdef WIN32
#include "Windows.h"
#else
#include <stdbool.h>
#endif

//*****************************************************
//RETURN CODES
//*****************************************************
//success
#define GR_OK                                         0
#define GR_BAD_QUALITY                                0
#define GR_MEDIUM_QUALITY                             1
#define GR_HIGH_QUALITY                               2
#define GR_MATCH                                      1
#define GR_NOT_MATCH                                  0
#define GR_DEFAULT_USED                               3
#define GR_ENROLL_NOT_READY                           0
#define GR_ENROLL_SUFFICIENT                          1
#define GR_ENROLL_GOOD                                2
#define GR_ENROLL_VERY_GOOD                           3
#define GR_ENROLL_MAX_LIMIT_REACHED                   4
//initialization errors codes
#define GR_ERROR_INITIALIZE_FAIL                     -1
#define GR_ERROR_CAPTURE_INITIALIZE_FAIL             -2
#define GR_ERROR_NOT_INITIALIZED                     -3
#define GR_ERROR_NO_LICENSE_FOUND                    -4
#define GR_ERROR_NO_VALID_LICENSE                    -5
#define GR_ERROR_NULL_ARGUMENT                       -6
#define GR_ERROR_FAIL                                -7
#define GR_ERROR_ALLOC                               -8
#define GR_ERROR_PARAMETERS                          -9
#define GR_ERROR_EXPIRED_LICENSE                     -10
//extract and match errors codes
#define GR_ERROR_WRONG_USE                         -107
#define GR_ERROR_EXTRACT                           -108
#define GR_ERROR_SIZE_OFF_RANGE                    -109
#define GR_ERROR_RES_OFF_RANGE                     -110
#define GR_ERROR_CONTEXT_NOT_CREATED               -111
#define GR_ERROR_INVALID_CONTEXT                   -112
#define GR_ERROR_ERROR                             -113
#define GR_ERROR_NOT_ENOUGH_SPACE                  -114
#define GR_ERROR_BAD_QUALITY                       -115
#define GR_ERROR_PROCESSED_IMAGE_NOT_EXTRACTED     -116
//capture error codes
#define GR_ERROR_CONNECT_SENSOR                    -201
#define GR_ERROR_CAPTURING                         -202
#define GR_ERROR_CANCEL_CAPTURING                  -203
#define GR_ERROR_INVALID_ID_SENSOR                 -204
#define GR_ERROR_SENSOR_NOT_CAPTURING              -205
#define GR_ERROR_INVALID_EXT                       -206
#define GR_ERROR_INVALID_FILENAME                  -207
#define GR_ERROR_INVALID_FILETYPE                  -208
#define GR_ERROR_SENSOR                            -209
//license error codes
#define GR_ERROR_GET_HARDWARE_KEY                  -301
#define GR_ERROR_INTERNET_CONNECTION               -302
#define GR_ERROR_BAD_REQUEST                       -303
#define GR_ERROR_INVALID_PRODUCT_KEY               -304
#define GR_ERROR_INSUFFICIENT_CREDIT               -305
#define GR_ERROR_NO_HARDWARE_BOUND                 -306
#define GR_ERROR_HTTP_AUTHORIZATION                -307
#define GR_ERROR_WRONG_PRODUCT_KEY                 -308
#define GR_ERROR_INTERNAL_SERVER                   -309
#define GR_ERROR_WRITING_LICENSE_FILE              -310
#define GR_ERROR_PK_NOT_LINKED                     -311
#define GR_ERROR_PK_NOT_APPROVED                   -312
// memory management constants
#define GR_INVALID_MEMORY_ADDRESS                  -401

//*****************************************************
//CONSTS
//*****************************************************
//file format codes
#define GRCAP_IMAGE_FORMAT_BMP                      501
//event values codes
#define GR_PLUG                                      21
#define GR_UNPLUG                                    20
#define GR_FINGER_DOWN                               11
#define GR_FINGER_UP                                 10
//image consts
#define GR_DEFAULT_RES                              500
#define GR_DEFAULT_DIM                              500
#define GR_MAX_SIZE_TEMPLATE                      10000
#define GR_MAX_IMAGE_WIDTH                         1280
#define GR_MAX_IMAGE_HEIGHT                        1280
#define GR_MAX_RESOLUTION                          1000 /*DPI*/
#define GR_MIN_IMAGE_WIDTH                           50
#define GR_MIN_IMAGE_HEIGHT                          50
#define GR_MIN_RESOLUTION                           125 /*DPI*/
//match const
#define GR_MAX_THRESHOLD                            200
#define GR_MIN_THRESHOLD                             10
#define GR_VERYLOW_FRR                               30 /*FAR 1 IN 1000*/
#define GR_LOW_FRR                                   45 /*FAR 1 IN 10000*/
#define GR_LOW_FAR                                   60 /*FAR 1 IN 30000*/
#define GR_VERYLOW_FAR                               80 /*FAR 1 IN 300000*/
#define GR_ROT_MIN                                    0
#define GR_ROT_MAX                                  180
//context const
#define GR_DEFAULT_CONTEXT                            0
#define GR_NO_CONTEXT                                -1
//colors for BiometricDisplay
#define GR_IMAGE_NO_COLOR                    0x1FFFFFFF
//version constants
#define GRFINGER_FULL                                 1
#define GRFINGER_LIGHT                                2
//Template format constants

//*****************************************************
//TYPE DEFINITIONS
//*****************************************************
/**
 * Capture types
 */
typedef enum {
    ctSlap,
	ctRolled,
	ctTwoFingers,
	ctFourFingers,
	ctTwoThumbs,
	ctPalmRightUp,
	ctPalmRightLower,
	ctPalmRightWriters,
	ctPalmLeftUp,
	ctPalmLeftLower,
	ctPalmLeftWriters,
	ctDisabled
} GrCaptureType;

/**
 * Template format defines which format is buffered template.
 */
typedef enum {
	DEFAULT				= 1,
	GR001				= 2,
	GR002				= 3,
	GR003				= 4,
	GR006				= 5,
	GR007				= 6,
	CLASSIC				= 7,
	ISO					= 8,
	ANSI				= 9
} GR_TEMPLATE_FORMAT;

/**
 * Determines whether the template is base 64 encoded or ascii
 */
typedef enum {
    BASE64,
    ASCII
} GR_ENCODING;

/**
 * Defines the IMAGE FORMAT
 */
typedef enum {
    RAW         = 0,
    RGB         = 1,
    BMP         = 2,
    BMP24BITS   = 3,
    GIF         = 4,
    JPEG        = 5,
    JPEG2000    = 6,
    PNG         = 7,
    #ifndef WIN64
    TIFF        = 8,
    #endif
    WSQ         = 9
} GR_IMAGE_FORMAT;

/**
 * The template
 */
typedef struct {
    unsigned char *buffer;
    int size;
    int quality;
    GR_TEMPLATE_FORMAT format;
    GR_ENCODING encoding;
} GR_TEMPLATE;

/**
 * Determines whether a minutia is a minutia (M), core (C) or delta (D)
 */
typedef enum {
    MINUTIA,
    CORE,
    DELTA
} GR_MINUTIA_TYPE;

/**
 * Minuta structure
 */
typedef struct {
    short x;
    short y;
    short angles[3];
    GR_MINUTIA_TYPE type;
    bool edited;
} GR_MINUTIA;

/**
 * Represents the result of a fingerprint quality analysis
 */
typedef struct {
	int direction;
	int reversions;
	int slips;
	int frames;
	bool dirty_start;
	bool dirty_latter;
} GR_FINGERPRINT_QUALITY;

/**
 * Image
 */
typedef struct {
	unsigned char *buffer;			///< The image buffer
	long length;					///< The length of the buffer
	int width;						///< Width
	int height;						///< Height
	int resolution;					///< Resolution
	GR_IMAGE_FORMAT format;			///< Format
	GR_FINGERPRINT_QUALITY quality; ///< The fingerprint quality
} GR_IMAGE;

/**
 * Represents an image list
 */
typedef struct {
    int size;
    GR_IMAGE **image;   ///<The image itself
} GR_IMAGE_ARRAY;

/**
 * The verification parameters
 */
typedef struct {
    int Threshold;
    int RotationTolerance;
} GR_VERIFY_PARAMETERS;

/**
 * The biometric display colors
 */
typedef struct {
    int Minutiae;
    int MatchedMinutiae;
    int Segment;
    int MatchedSegment;
    int Direction;
    int MatchedDirection;
} GR_BIOMETRIC_DISPLAY_COLORS;

/**
 * The software version
 */
typedef struct {
    unsigned int major;
    unsigned int minor;
    unsigned int build;
    unsigned int revision;
} GR_VERSION;

/**
 * Determines the processed image options
 */
typedef enum {
    Quality,
    Directional,
    FFT
} GR_PROCESSED_IMAGE_TYPE;

/**
 * Configures the extraction parameters
 */
typedef struct {
    /**
     * Flags the extractor to extract the template singularities.
     */
    bool singularities;

    /**
     * Flags the extraction of processed images
     */
    bool processedImages;

    /**
     * Flags the extraction to get the FFT image
     */
    bool fft;
} GR_EXTRACTION_PARAMETERS;

/**
 * Defines the Bitmap compression mode
 */
typedef enum {
    BMP_COMPRESSION_NONE,
    BMP_COMPRESSION_RLE
} GR_BMP_COMPRESSION_MODE;

/**
 * Defines the Tiff compression mode
 */
typedef enum {
    TIFF_COMPRESSION_NONE           = 1,     /* dump mode */
    TIFF_COMPRESSION_LZW            = 5,     /* Lempel-Ziv  & Welch */
    TIFF_COMPRESSION_PACKBITS       = 32773, /* Macintosh RLE */
    TIFF_COMPRESSION_JPEG           = 7,     /* %JPEG DCT compression */
    TIFF_COMPRESSION_CCITTRLE       = 2,     /* CCITT modified Huffman RLE */
    TIFF_COMPRESSION_CCITTFAX3      = 3,     /* CCITT Group 3 fax encoding */
    TIFF_COMPRESSION_CCITTFAX4      = 4,     /* CCITT Group 4 fax encoding */
    TIFF_COMPRESSION_DEFLATE        = 32946, /* Deflate compression */
    TIFF_COMPRESSION_ADOBE_DEFLATE  = 8      /* Deflate compression, as recognized by Adobe */
} GR_TIFF_COMPRESSION_MODE;

/**
 * Defines the images parameters
 */
typedef struct {
    /**
     * BMP Compression mode could be one of both None or RLE
     */
    GR_BMP_COMPRESSION_MODE BMPCompressionMode;

    /**
     * Tiff Compression Mode
     */
    GR_TIFF_COMPRESSION_MODE TIFFCompressionMode;

    /**
     * Tiff Deflate compression parameter
     */
    int TIFFDeflateCompression;

    /**
     * The JPEG image quality varies from 1 to 100
     */
    int JPEGQuality;

    /**
     * The JPEG 2000 Compression varies from 1 to 1000
     */
    int JPEG2000Compression;

    /**
     * The WSQ Compression rate
     */
    int WSQCompressionRate;

} GR_IMAGE_CONVERSION_PARAMETERS;

/**
 * A match pair
 */
typedef struct {
	short query;
	short reference;
} GR_MATCH_PAIR;

/**
 * Point
 */
typedef struct {
	short x;
	short y;
} GR_POINT;

/**
 * Griaule Spoof Detect Methods
 */
typedef enum {
	GR_BFX9
} GR_GSD_METHOD;

#ifdef WIN32
#define DLLIMPORT extern "C" __declspec(dllimport) int __stdcall
#define CALLBACK __stdcall
#else
#define DLLIMPORT extern "C" __attribute__ ((visibility("default"))) int
#define CALLBACK
#endif

typedef int GRCAP_STATUS_EVENTS;
typedef int GRCAP_FINGER_EVENTS;
typedef int GRCAP_IMAGE_FORMAT;
typedef long BITMAP_HANDLE;

// Fingerprint CALLBACKs
typedef void CALLBACK GBSFINGERPRINT_STATUS_EVENT_CALLBACK  (char* idSensor, GRCAP_STATUS_EVENTS event);
typedef void CALLBACK GBSFINGERPRINT_FINGER_EVENT_CALLBACK  (char* idSensor, GRCAP_FINGER_EVENTS event);
typedef void CALLBACK GBSFINGERPRINT_IMAGE_EVENT_CALLBACK   (char* idSensor, GR_IMAGE *image);
typedef void CALLBACK GBSFINGERPRINT_FRAME_EVENT_CALLBACK   (char* idSensor, GR_IMAGE *frame);


/***********************************************************************************************************************
 * Extraction functions                                                                                                *
 ***********************************************************************************************************************/

/**
 * Extracts a fingerprint template from the supplied fingerprint raw image.
 *
 * The following code extracts a template from an image loaded from a file, gets the biometric display for it and saves
 * it to another file.
 * @code{.cpp}
 * GR_IMAGE *fileImage;
 * GR_IMAGE *rawImage;
 * GR_TEMPLATE *tpt;
 *
 * GrLoadFromFile("C:/fingerprint.png", &fileImage);
 *
 * GrConvertImage(fileImage, RAW, &rawImage);
 *
 * // Negative values are errors
 * if (GrExtract(rawImage, DEFAULT, BASE64, &tpt) < 0) {
 *     tpt = NULL;
 * } else {
 *     GR_BIOMETRIC_DISPLAY_COLORS colors;
 *     GR_IMAGE *bioImage, bioPNGImage;
 *
 *     colors.Direction        = 0xFF0000;
 *     colors.MatchedDirection = 0xFF00FF;
 *     colors.Minutiae         = 0x00FF00;
 *     colors.MatchedMinutiae  = 0xFF00FF;
 *     colors.Segment          = 0x0000FF;
 *     colors.MatchedSegment   = 0xFF00FF;
 *
 *     GrSetBiometricDisplayColors(colors);
 *
 *     GrBiometricDisplay(rawImage, tpt, &bioImage);
 *     GrConvertImage(bioImage, PNG, &bioPNGImage);
 *
 *     GrSaveToFile(bioPNGImage, "C:/bioFingerprint.png");
 *
 *     GrFreeTemplate(&tpt);
 *     GrFreeImage(&bioImage);
 *     GrFreeImage(&bioPNGImage);
 * }
 *
 * GrFreeImage(&fileImage);
 * GrFreeImage(&rawImage);
 * @endcode
 *
 * The following code listens to the image capture event and automatically extracts the image returned. For information
 * on how to listen for the image capture event, see GrCapStartCapture().
 * @code{.cpp}
 * GBSFINGERPRINT_IMAGE_EVENT_CALLBACK onImageCapture(char* idSensor, GR_IMAGE *image) {
 *     GR_IMAGE *rawImage;
 *     GR_TEMPLATE *tpt;
 *
 *     GrConvertImage(image, RAW, &rawImage);
 *
 *     // Negative values are errors
 *     if (GrExtract(rawImage, DEFAULT, BASE64, &tpt) < 0) {
 *         tpt = NULL;
 *     } else {
 *         // Do something useful with your extracted template
 *         DoSomething(tpt);
 *
 *         GrFreeTemplate(&tpt);
 *     }
 *
 *     GrFreeImage(&image);
 *     GrFreeImage(&rawImage);
 * }
 * @endcode
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in]  fingerprint A raw grayscale fingerprint image
 * @param[in]  format      The format desired for the extracted template
 * @param[in]  encoding    The encoding desired for the extracted template
 * @param[out] tpt         The GR_TEMPLATE in which the extracted template will be stored; this must be freed after being
 *                         used by calling GrFreeTemplate()
 *
 * @return     On success, the template quality code is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_BAD_QUALITY
 * @retval     GR_MEDIUM_QUALITY
 * @retval     GR_HIGH_QUALITY
 * @retval     GR_ERROR_BAD_QUALITY
 * @retval     GR_ERROR_CONVERSION
 * @retval     GR_ERROR_ERROR
 * @retval     GR_ERROR_EXTRACT
 * @retval     GR_ERROR_INSUFFICIENT_MEMORY
 * @retval     GR_ERROR_INVALID_CONTEXT
 * @retval     GR_ERROR_INVALID_CONVERSION
 * @retval     GR_ERROR_INVALID_FILE_TYPE
 * @retval     GR_ERROR_INVALID_IMAGE_FILENAME
 * @retval     GR_ERROR_INVALID_IMAGE_FORMAT
 * @retval     GR_ERROR_NOT_ENOUGH_SPACE
 * @retval     GR_ERROR_NOT_INITIALIZED
 * @retval     GR_ERROR_NULL_ARGUMENT
 */
DLLIMPORT GrExtract(GR_IMAGE *fingerprint, GR_TEMPLATE_FORMAT format, GR_ENCODING encoding, GR_TEMPLATE **tpt);

/**
 * Sets the desired extractions parameters.
 *
 * The following code enables all existing parameters for the extraction. For information on what parameters are
 * available and what they do, see GR_EXTRACTION_PARAMETERS.
 * @code{.cpp}
 * GR_EXTRACTION_PARAMETERS parameters;
 *
 * parameters.fft             = true;
 * parameters.singularities   = true;
 * parameters.processedImages = true;
 *
 * GrSetExtractionParameters(parameters);
 * @endcode
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in]  parameters The desired extraction parameters to be set
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_OK
 * @retval     GR_ERROR_INVALID_CONTEXT
 * @retval     GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrSetExtractionParameters(GR_EXTRACTION_PARAMETERS parameters);

/***********************************************************************************************************************
 * Template Conversion functions                                                                                       *
 ***********************************************************************************************************************/

/**
 * Converts a template into a different template, possibly using different format and/or encoding.
 *
 * The following code converts a given template, obtained from a previous call to GrExtract(), into a new template using
 * ASCII encoding and the same format.
 * @code{.cpp}
 * GR_TEMPLATE asciiTemplate;
 *
 * GrConvertTemplate(tpt, tpt.format, ASCII, &asciiTemplate);
 * GrFreeTemplate(tpt);
 * @endcode
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in]  tpt         The original template to be converted
 * @param[in]  format      The format desired for the converted template
 * @param[in]  encoding    The encoding desired for the converted template
 * @param[out] result      The GR_TEMPLATE in which the converted template will be stored; this must be freed after being
 *                         used by calling GrFreeTemplate()
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_OK
 * @retval     GR_ERROR_ERROR
 * @retval     GR_ERROR_INVALID_FILE_TYPE
 * @retval     GR_ERROR_NOT_ENOUGH_SPACE
 * @retval     GR_ERROR_NOT_INITIALIZED
 * @retval     GR_ERROR_NULL_ARGUMENT
 */
DLLIMPORT GrConvertTemplate(GR_TEMPLATE *tpt, GR_TEMPLATE_FORMAT format, GR_ENCODING encoding, GR_TEMPLATE **result);


/***********************************************************************************************************************
 * Memory management functions                                                                                         *
 ***********************************************************************************************************************/

/**
 * Frees the memory allocated to store an image.
 *
 * For an example, see GrExtract().
 *
 * @note      The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in] image The image to be freed
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_INVALID_MEMORY_ADDRESS
 * @retval    GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrFreeImage(GR_IMAGE **image);

/**
 * Frees the memory allocated to store an array of images.
 *
 * For an example, see GrSegmentNFingers().
 *
 * @note      The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in] list The image list to be freed
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_INVALID_MEMORY_ADDRESS
 * @retval    GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrFreeImageList(GR_IMAGE_ARRAY **list);

/**
 * Frees the memory allocated to store a template.
 *
 * For an example, see GrConvertTemplate().
 *
 * @note      The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in] tpt The template to be freed
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_INVALID_MEMORY_ADDRESS
 * @retval    GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrFreeTemplate(GR_TEMPLATE **tpt);

/**
 * Frees all the memory allocated to store images, templates and minutiae.
 *
 * @note   The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @return On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval GR_OK
 * @retval GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrFlushMemory(void);


/***********************************************************************************************************************
 * Initializing functions                                                                                              *
 ***********************************************************************************************************************/

/**
 * Initializes the GBS Fingerprint SDK library and checks for a valid license on system.
 *
 * The following code attempts to initialize the GBS Fingerprint SDK and, if it succeeds, initializes the capture module.
 * @code{.cpp}
 * int ret = GrInitialize();
 * if (ret == GR_OK) {
 *     GrCapInitialize(&onDeviceEvent);
 * } else {
 *     // Initialization failed
 * }
 * @endcode
 *
 * @note   A valid license must exist on the system or on a floating license server.
 *
 * @return On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval GR_OK
 * @retval GR_ERROR_ALLOC
 * @retval GR_ERROR_INITIALIZATION_FAILED
 * @retval GR_ERROR_NO_LICENSE_FOUND
 * @retval GR_ERROR_NO_VALID_LICENSE
 */
DLLIMPORT GrInitialize(void);

/**
 * Finalizes the GBS Fingerprint SDK library, freeing all resources used.
 *
 * @note   The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @return On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval GR_OK
 * @retval GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrFinalize(void);


/***********************************************************************************************************************
 * Capturing & Plugins functions                                                                                       *
 ***********************************************************************************************************************/

/**
 * Initializes the fingerprint capture module and starts listening to USB ports for plug and unplug events.
 *
 * The following code initializes the capturing to register a callback and listen to the plug and unplug events.
 * @code{.cpp}
 * if (GrInitialize() == GR_OK) {
 *     GrCapInitialize(&onDeviceEvent);
 * }
 * @endcode
 * @code{.cpp}
 * GBSFINGERPRINT_STATUS_EVENT_CALLBACK onDeviceEvent(char* idSensor, GRCAP_STATUS_EVENTS event) {
 *     switch (event) {
 *          case GR_PLUG:
 *              // Sensor plugged
 *              break;
 *
 *          case GR_UNPLUG:
 *              // Sensor unplugged
 *              break;
 *     }
 * }
 * @endcode
 *
 * @note      The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in] statusCallback Callback responsible of handling all status events
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_ERROR
 * @retval    GR_ERROR_CAPTURE_INITIALIZE_FAIL
 * @retval    GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrCapInitialize(GBSFINGERPRINT_STATUS_EVENT_CALLBACK *statusCallback);

/**
 * Finalizes the fingerprint capture module and stops listening to USB ports for plug and unplug events.
 *
 * @note   The fingerprint capture module must have been previously initialized.
 *
 * @return On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval GR_OK
 * @retval GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrCapFinalize();

/**
 * Sets the automatic capture type for all fingerprint readers.
 *
 * The following code checks the capture type currently set for a previously connected reader; if it's not rolled, sets
 * it to rolled type.
 * @code{.cpp}
 * GrCaptureType capType;
 *
 * GrCapGetAutomaticCaptureType(idSensor, &capType);
 *
 * if (capType != ctRolled) {
 *     GrCapSetAutomaticCaptureType(ctRolled);
 * }
 * @endcode
 *
 * @note      The fingerprint capture module must have been previously initialized.
 *
 * @param[in] automaticType The capture type to be set
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrCapSetAutomaticCaptureType(GrCaptureType automaticType);

/**
 * Gets the automatic capture type for the supplied fingerprint reader.
 *
 * For an example, see GrCapSetAutomaticCaptureType().
 *
 * @note       The fingerprint capture module must have been previously initialized.
 *
 * @param[in]  idSensor      The id of the fingerprint reader
 * @param[out] automaticType The current capture type
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_OK
 * @retval     GR_ERROR_ERROR
 * @retval     GR_ERROR_ALLOC
 * @retval     GR_ERROR_CONNECT_SENSOR
 * @retval     GR_ERROR_INVALID_ID_SENSOR
 * @retval     GR_ERROR_NO_LICENSE_FOUND
 * @retval     GR_ERROR_NO_VALID_LICENSE
 * @retval     GR_ERROR_NOT_INITIALIZED
 * @retval     GR_ERROR_NULL_ARGUMENT
 * @retval     GR_ERROR_PARAMETERS
 * @retval     GR_ERROR_WRONG_USE
 */
DLLIMPORT GrCapGetAutomaticCaptureType(char* idSensor, GrCaptureType* automaticType);

/**
 * Starts capturing fingerprint images from the supplied fingerprint reader.
 *
 * The following code starts capturing fingerprint images from a previously connected fingerprint reader and sets no
 * frame callback.
 * @code{.cpp}
 * if (GrCapStartCapture(sensor, onFingerEvent, onImageCapture, NULL) == GR_OK) {
 *     // Capture successfully started
 * }
 * @endcode
 * @code{.cpp}
 * GBSFINGERPRINT_FINGER_EVENT_CALLBACK onFingerEvent(char* idSensor, GRCAP_FINGER_EVENTS event) {
 *     switch (event) {
 *         case GR_FINGER_DOWN:
 *             // Finger just landed on sensor
 *             break;
 *
 *         case GR_FINGER_UP:
 *             // Finger just left the sensor
 *             break;
 *     }
 * }
 *
 * GBSFINGERPRINT_IMAGE_EVENT_CALLBACK onImageCapture(char* idSensor, GR_IMAGE *image) {
 *     char filePath[12];
 *     GR_IMAGE *pngImage;
 *
 *     // Save file as C:/{device}.png
 *     strcpy(filePath, "C:/");
 *     strcat(filePath, device);
 *     strcat(filePath, ".png");
 *
 *     GrConvertImage(image, PNG, &pngImage);
 *
 *     GrSaveToFile(pngImage, filePath);
 *
 *     GrFreeImage(&image);
 *     GrFreeImage(&pngImage);
 * }
 * @endcode
 *
 * The following code listens to the device events and starts/stops capturing as soon as a device is plugged/unplugged,
 * using the same event handlers as the previous example. For information on how to listen for the device events, see
 * GrCapInitialize().
 * @code{.cpp}
 * GBSFINGERPRINT_STATUS_EVENT_CALLBACK onDeviceEvent(char* idSensor, GRCAP_STATUS_EVENTS event) {
 *     switch (event) {
 *          case GR_PLUG:
 *              GrCapStartCapture(idSensor, onFingerEvent, onImageCapture, NULL);
 *              break;
 *
 *          case GR_UNPLUG:
 *              GrCapStopCapture(idSensor);
 *              break;
 *     }
 * }
 * @endcode
 *
 * @note      The fingerprint capture module must have been previously initialized.
 * @note      The supplied fingerprint reader must be connected, working and recognized as plugged by the capture module.
 *
 * @param[in] idSensor       The id of the fingerprint reader
 * @param[in] fingerCallback Callback responsible of handling all finger events
 * @param[in] imageCallback  Callback responsible of handling the image event
 * @param[in] frameCallback  Callback responsible of handling the frame event; this is only raised on rolled captures
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_ERROR
 * @retval    GR_ERROR_ALLOC
 * @retval    GR_ERROR_CAPTURE_INITIALIZE_FAIL
 * @retval    GR_ERROR_CONNECT_SENSOR
 * @retval    GR_ERROR_INVALID_ID_SENSOR
 * @retval    GR_ERROR_NO_LICENSE_FOUND
 * @retval    GR_ERROR_NO_VALID_LICENSE
 * @retval    GR_ERROR_NOT_INITIALIZED
 * @retval    GR_ERROR_NULL_ARGUMENT
 * @retval    GR_ERROR_PARAMETERS
 * @retval    GR_ERROR_WRONG_USE
 */
DLLIMPORT GrCapStartCapture(char* idSensor, GBSFINGERPRINT_FINGER_EVENT_CALLBACK *fingerCallback, GBSFINGERPRINT_IMAGE_EVENT_CALLBACK *imageCallback, GBSFINGERPRINT_FRAME_EVENT_CALLBACK *frameCallback);

/**
 * Stops capturing fingerprint images from the supplied fingerprint reader.
 *
 * For an example, see GrCapStartCapture().
 *
 * @note      The fingerprint capture module must have been previously initialized.
 * @note      Image capture must have been previously started on the supplied fingerprint reader.
 *
 * @param[in] idSensor The id of the fingerprint reader
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_ERROR
 * @retval    GR_ERROR_ALLOC
 * @retval    GR_ERROR_CONNECT_SENSOR
 * @retval    GR_ERROR_INVALID_ID_SENSOR
 * @retval    GR_ERROR_NO_LICENSE_FOUND
 * @retval    GR_ERROR_NO_VALID_LICENSE
 * @retval    GR_ERROR_NOT_INITIALIZED
 * @retval    GR_ERROR_PARAMETERS
 * @retval    GR_ERROR_WRONG_USE
 */
DLLIMPORT GrCapStopCapture(char* idSensor);

/**
 * Gets information for the supplied fingerprint reader, as a query string. The information contained in the query
 * string varies for different readers.
 *
 * The following code attempts to get information for a previously connected fingerprint reader.
 * @code{.cpp}
 * char *readerInfo;
 *
 * if (GrCapGetReaderInfo(sensor, &readerInfo) == GR_OK) {
 *     // Do something useful
 *     doSomething(readerInfo);
 *
 *     GrFreeInfo(&readerInfo);
 * }
 * @endcode
 *
 * @note       The fingerprint capture module must have been previously initialized.
 * @note       The supplied fingerprint reader must be connected, working and recognized as plugged by the capture module.
 *
 * @param[in]  idSensor The id of the fingerprint reader
 * @param[out] info     The information for the supplied fingerprint reader; this must be freed after being used by
 *                      calling GrFreeInfo().
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_OK
 * @retval     GR_ERROR_ERROR
 * @retval     GR_ERROR_ALLOC
 * @retval     GR_ERROR_CONNECT_SENSOR
 * @retval     GR_ERROR_INVALID_ID_SENSOR
 * @retval     GR_ERROR_NO_LICENSE_FOUND
 * @retval     GR_ERROR_NO_VALID_LICENSE
 * @retval     GR_ERROR_NOT_INITIALIZED
 * @retval     GR_ERROR_NULL_ARGUMENT
 * @retval     GR_ERROR_PARAMETERS
 * @retval     GR_ERROR_WRONG_USE
 */
DLLIMPORT GrCapGetReaderInfo(char *idSensor, char **info);

/**
 * Sets information for the supplied fingerprint reader, as a query string.
 *
 * The following code attempts to set information for a previously connected fingerprint reader, enabling a red led.
 * @code{.cpp}
 * if (GrCapSetReaderInfo(sensor, "LED_RED=1") == GR_OK) {
 *     // Do something useful
 *     doSomething(readerInfo);
 * }
 * @endcode
 *
 * @note      The fingerprint capture module must have been previously initialized.
 * @note      The supplied fingerprint reader must be connected, working and recognized as plugged by the capture module.
 *
 * @param[in] idSensor The id of the fingerprint reader
 * @param[in] info     The information for the supplied fingerprint reader
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_ERROR
 * @retval    GR_ERROR_ALLOC
 * @retval    GR_ERROR_CONNECT_SENSOR
 * @retval    GR_ERROR_INVALID_ID_SENSOR
 * @retval    GR_ERROR_NO_LICENSE_FOUND
 * @retval    GR_ERROR_NO_VALID_LICENSE
 * @retval    GR_ERROR_NOT_INITIALIZED
 * @retval    GR_ERROR_NULL_ARGUMENT
 * @retval    GR_ERROR_PARAMETERS
 * @retval    GR_ERROR_WRONG_USE
 */
DLLIMPORT GrCapSetReaderInfo(char *idSensor, char *info);


/***********************************************************************************************************************
 * Versioning functions                                                                                                *
 ***********************************************************************************************************************/

/**
 * Retrieves the GBS Fingerprint SDK version.
 *
 * The following code retrieves the GBS Fingerprint SDK version.
 * @code{.cpp}
 * GR_VERSION version;
 * GrVersion(&version);
 * @endcode
 *
 * @note A valid license must exist on the system or on a floating license server.
 *
 * @param[out] version Current GBS Fingerprint SDK version
 *
 * @retval     GR_OK
 */
DLLIMPORT GrVersion(GR_VERSION *version);


/***********************************************************************************************************************
 * Verification functions                                                                                              *
 ***********************************************************************************************************************/

/**
 * Sets the verification parameters.
 *
 * For an example, see GrVerify().
 *
 * @note      The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in] parameters The desired verification parameters
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_DEFAULT_USED
 * @retval    GR_ERROR_INVALID_CONTEXT
 * @retval    GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrSetVerifyParameters(GR_VERIFY_PARAMETERS parameters);

/**
 * Gets the verification parameters.
 *
 * The following code attempts to retrieve the current verification parameters.
 * @code{.cpp}
 * GR_VERIFY_PARAMETERS verifyParams;
 *
 * if (GrGetVerifyParameters(&verifyParams) == GR_OK) {
 *     // Do something with the parameters
 * }
 * @endcode
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[out] parameters The current verification parameters
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_OK
 * @retval     GR_ERROR_INVALID_CONTEXT
 * @retval     GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrGetVerifyParameters(GR_VERIFY_PARAMETERS *parameters);

/**
 * Performs a verification by comparing the two supplied templates.
 *
 * The following code sets a minimum score of 35 for matching and verifies if two templates extracted from two
 * previously acquired raw images match.
 * @code{.cpp}
 * int matchScore;
 * GR_TEMPLATE *tptOne, tptTwo;
 * GR_VERIFY_PARAMETERS verifyParams;
 *
 * GrExtract(imageOne, DEFAULT, BASE64, &tptOne);
 * GrExtract(imageTwo, DEFAULT, BASE64, &tptTwo);
 *
 * verifyParams.Threshold = 35;
 * verifyParams.RotationTolerance = 90;
 * GrSetVerifyParameters(verifyParams);
 *
 * int ret = GrVerify(tptOne, tptTwo, &matchScore);
 * if (ret < 0) {
 *     // Something went wrong
 * } else {
 *     if (ret == GR_NOT_MATCH) {
 *         // Templates don't match, matchScore < 35
 *     } else {
 *         // Templates match, matchScore >= 35
 *     }
 * }
 *
 * GrFreeTemplate(&tptOne);
 * GrFreeTemplate(&tptTwo);
 * @endcode
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in]  query     Query template to be verified
 * @param[in]  reference Reference template for verification
 * @param[out] score     Verification matching score
 *
 * @return     On success, `GR_MATCH` is returned if the matching score is higher than the verification threshold,
 *             `GR_NOT_MATCH` otherwise. On failure, the appropriate error code is returned.
 *
 * @retval     GR_MATCH
 * @retval     GR_NOT_MATCH
 * @retval     GR_ERROR_ALLOC
 * @retval     GR_ERROR_ERROR
 * @retval     GR_ERROR_INVALID_CONTEXT
 * @retval     GR_ERROR_INVALID_TEMPLATE
 * @retval     GR_ERROR_NOT_INITIALIZED
 * @retval     GR_ERROR_NULL_ARGUMENT
 * @retval     GR_ERROR_PARAMETERS
 * @retval     GR_ERROR_WRONG_USE
 */
DLLIMPORT GrVerify(GR_TEMPLATE *query, GR_TEMPLATE *reference, int *score);


/***********************************************************************************************************************
 * Consolidation functions                                                                                             *
 ***********************************************************************************************************************/

/**
 * Starts a consolidation process.
 *
 * For an example, see GrConsolidate().
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval GR_OK
 * @retval GR_ERROR_ALLOC
 * @retval GR_ERROR_INVALID_CONTEXT
 * @retval GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrStartConsolidation(void);

/**
 * Consolidates a template using the supplied fingerprint image.
 *
 * The following code starts capturing images on a previously connected sensor to consolidate a template, listening
 * to the image capture event. For information on how to listen for the image capture event, see GrCapStartCapture().
 * @code{.cpp}
 * int *quality;
 * GR_TEMPLATE *consTpt;
 *
 * GrStartConsolidation();
 * GrCapStartCapture(idSensor, NULL, onImageCapture, NULL);
 * @endcode
 * @code{.cpp}
 * GBSFINGERPRINT_IMAGE_EVENT_CALLBACK onImageCapture(char* idSensor, GR_IMAGE *image) {
 *    GR_IMAGE *rawImage;
 *
 *    GrConvertImage(image, RAW, &rawImage);
 *
 *    int ret = GrConsolidate(rawImage, DEFAULT, ASCII, &consTpt, &quality);
 *
 *    if (ret < 0) {
 *        // Error
 *        if (consTpt != NULL) {
 *            GrFreeTemplate(consTpt);
 *        }
 *
 *        consTpt = NULL;
 *        GrCapStopCapture(idSensor);
 *    } else if (ret > 0) {
 *        // Consolidation completed
 *
 *        // Do something with the consolidated template
 *        doSomething(consTpt, quality);
 *
 *        GrFreeTemplate(&consTpt);
 *        GrCapStopCapture(idSensor);
 *    }
 *
 *    GrFreeImage(&image);
 *    GrFreeImage(&rawImage);
 * }
 * @endcode
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 * @note       A consolidation process must have been previously started.
 *
 * @param[in]  fingerprint A raw grayscale fingerprint image
 * @param[in]  format      The format desired for the consolidated template
 * @param[in]  encoding    The encoding desired for the consolidated template
 * @param[out] result      The GR_TEMPLATE in which the consolidated template will be stored; this must be freed after
 *                         being used by calling GrFreeTemplate()
 * @param[out] quality     The extraction quality for the consolidated template
 *
 * @return     On success, the current status of the consolidation is returned. On failure, the appropriate error code is returned.
 *
 * @retval GR_ENROLL_NOT_READY
 * @retval GR_ENROLL_GOOD
 * @retval GR_ENROLL_MAX_LIMIT_REACHED
 * @retval GR_ENROLL_SUFFICIENT
 * @retval GR_ENROLL_VERY_GOOD
 * @retval GR_ERROR_ERROR
 * @retval GR_ERROR_CONVERSION
 * @retval GR_ERROR_INSUFICIENT_MEMORY
 * @retval GR_ERROR_INVALID_CONTEXT
 * @retval GR_ERROR_INVALID_CONVERSION
 * @retval GR_ERROR_INVALID_MEMORY_ADDRESS
 * @retval GR_ERROR_NOT_INITIALIZED
 * @retval GR_ERROR_NULL_ARGUMENT
 * @retval GR_ERROR_PARAMETERS
 */
DLLIMPORT GrConsolidate(GR_IMAGE *fingerprint, GR_TEMPLATE_FORMAT format, GR_ENCODING encoding, GR_TEMPLATE **result, int *quality);


/***********************************************************************************************************************
 * Biometric display functions                                                                                         *
 ***********************************************************************************************************************/

/**
 * Draws over a fingerprint image all minutiae and segments contained in the supplied template.
 *
 * For an example, see GrExtract().
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in]  image  The original fingerprint image
 * @param[in]  tpt    The template extracted from the image
 * @param[out] result The resulting image with all elements drawn, in RGB format; this must be freed after being used
 *                    by calling GrFreeImage()
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_OK
 * @retval     GR_ERROR_INVALID_CONTEXT
 * @retval     GR_ERROR_INVALID_IMAGE_FORMAT
 * @retval     GR_ERROR_INVALID_TEMPLATE
 * @retval     GR_ERROR_NOT_INITIALIZED
 * @retval     GR_ERROR_NULL_ARGUMENT
 * @retval     GR_ERROR_PARAMETERS
 * @retval     GR_ERROR_WRONG_USE
 */
DLLIMPORT GrBiometricDisplay(GR_IMAGE *image, GR_TEMPLATE *tpt, GR_IMAGE **result);

/**
 * Sets the colors used for the biometric display for each element.
 *
 * For an example, see GrExtract().
 *
 * @note      The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in] parameters The colors used for the biometric display
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_INVALID_CONTEXT
 * @retval    GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrSetBiometricDisplayColors(GR_BIOMETRIC_DISPLAY_COLORS parameters);


/******************************************************************************************
 * Licensing Functions                                                                    *
 ******************************************************************************************/

/**
 * Sets the server host in which GBS Fingerprint SDK should search for its floating licenses.
 *
 * The following code sets the license server address to '192.168.1.1' on port 8002.
 * @code{.cpp}
 * GrSetLicenseServerHost("http://192.168.1.1:8002");
 * @endcode
 *
 * @note      This method must be called before the initialization of the GBS Fingerprint SDK library.
 *
 * @param[in] host The server host in which GBS Fingerprint SDK should search for its floating licenses
 *
 * @retval GR_OK
 */
DLLIMPORT GrSetLicenseServerHost(char *host);

/**
 * Gets the server host in which GBS Fingerprint SDK should search for its floating licenses.
 *
 * The following code gets the server host address.
 * @code{.cpp}
 * char serverHost[200];
 * GrGetLicenseServerHost(serverHost, 199);
 * @endcode
 *
 * @param[out] host The server host in which GBS Fingerprint SDK should search for its floating licenses
 * @param[in]  size The maximum size expected for the server host
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval GR_OK
 * @retval GR_ERROR_INSUFICIENT_MEMORY
 */
DLLIMPORT GrGetLicenseServerHost(char *host, int size);

/**
 * Sets the directory in which GBS Fingerprint SDK should search for its runtime license file.
 *
 * The following code sets the license folder to the root of your C: driver.
 * @code{.cpp}
 * GrSetLicenseFolder("C:/");
 * @endcode
 *
 * @note      This method must be called before the initialization of the GBS Fingerprint SDK library.
 *
 * @param[in] licenseFolder The directory in which GBS Fingerprint SDK should search for its runtime license file
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_NO_LICENSE_FOUND
 * @retval    GR_ERROR_NO_VALID_LICENSE
 */
DLLIMPORT GrSetLicenseFolder(char *licenseFolder);

/**
 * Gets the directory in which GBS Fingerprint SDK should search for its runtime license file.
 *
 * The following code gets the license folder.
 * @code{.cpp}
 * char licenseFolder[200];
 * GrGetLicenseFolder(licenseFolder, 199);
 * @endcode
 *
 * @param[out] licenseFolder The directory in which GBS Fingerprint SDK should search for its runtime license file
 * @param[in]  size          The maximum size expected for the license folder
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_OK
 * @retval     GR_ERROR_INSUFICIENT_MEMORY
 */
DLLIMPORT GrGetLicenseFolder(char *licenseFolder, int size);

/**
 * Installs a license based on the product key.
 *
 * The following code attempts to install a license. If it succeeds, initializes the SDK.
 * @code{.cpp}
 * int ret = GrInstallLicense("XXXX-XXXX-XXXX-XXXX");
 * if (ret == GR_OK) {
 *     GrInitialize();
 * }
 * @endcode
 *
 * @note      This method must be called before the initialization of the GBS Fingerprint SDK library.
 *
 * @param[in] productKey The product key
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_NO_LICENSE_FOUND
 * @retval    GR_ERROR_NO_VALID_LICENSE
 */
DLLIMPORT GrInstallLicense(char *productKey);


/******************************************************************************************
 * WSQ Functions                                                                          *
 ******************************************************************************************/

/**
 * Converts the supplied image into a another image, using a different format.
 *
 * For an example, see GrExtract().
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in]  image     The original image to be converted
 * @param[in]  format    The format desired for the converted image
 * @param[out] converted The GR_IMAGE in which the converted image will be stored; this must be freed after being used
 *                       by calling GrFreeImage()
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.

 * @retval     GR_OK
 * @retval     GR_ERROR_CONVERSION
 * @retval     GR_ERROR_INSUFICIENT_MEMORY
 * @retval     GR_ERROR_INVALID_CONTEXT
 * @retval     GR_ERROR_INVALID_CONVERSION
 * @retval     GR_ERROR_NOT_INITIALIZED
 * @retval     GR_ERROR_NULL_ARGUMENT
 * @retval     GR_ERROR_PARAMETERS
 */
DLLIMPORT GrConvertImage(GR_IMAGE *image, GR_IMAGE_FORMAT format, GR_IMAGE **converted);

/**
 * Saves an image to a file.
 *
 * For an example, see GrCapStartCapture().
 *
 * @note      The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in] image    The image to be saved
 * @param[in] filepath The path to save the image on
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval    GR_OK
 * @retval    GR_ERROR_CANNOT_OPEN_FILE
 * @retval    GR_ERROR_INVALID_CONTEXT
 * @retval    GR_ERROR_NOT_INITIALIZED
 * @retval    GR_ERROR_NULL_ARGUMENT
 */
DLLIMPORT GrSaveToFile(GR_IMAGE *image, char *filepath);

/**
 * Loads an image from a file.
 *
 * For an example, see GrExtract().
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in]  filepath The path to load the image from
 * @param[out] image    The image to load; this must be freed after being used by calling GrFreeImage()
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_OK
 * @retval     GR_ERROR_CANNOT_OPEN_FILE
 * @retval     GR_ERROR_INVALID_CONTEXT
 * @retval     GR_ERROR_NOT_INITIALIZED
 * @retval     GR_ERROR_NULL_ARGUMENT
 * @retval     GR_ERROR_UNSUPPORTED_FORMAT
 */
DLLIMPORT GrLoadFromFile(char *filepath, GR_IMAGE **image);

/**
 * Gets the image conversion parameters.
 *
 * For an example, see GrSetImageConversionParameters().
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[out] parameters The current image conversion parameters
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval     GR_OK
 * @retval     GR_ERROR_INVALID_CONTEXT
 * @retval     GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrGetImageConversionParameters(GR_IMAGE_CONVERSION_PARAMETERS *parameters);

/**
 * Sets the image conversion parameters.
 *
 * The following code alters the current image conversion parameters to set the JPEQ quality to 100.
 * @code{.cpp}
 * GR_IMAGE_CONVERSION_PARAMETERS parameters;
 *
 * GrGetImageConversionParameters(&parameters);
 *
 * parameters.JPEGQuality = 100;
 *
 * GrSetImageConversionParameters(parameters);
 * @endcode
 *
 * @note      The GBS Fingerprint SDK library must have been previously initialized.
 *
 * @param[in] parameters The desired image conversion parameters
 *
 * @return    On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval GR_OK
 * @retval GR_ERROR_INVALID_CONTEXT
 * @retval GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrSetImageConversionParameters(GR_IMAGE_CONVERSION_PARAMETERS parameters);

/**
 * @retval GR_OK
 * @retval GR_ERROR_FAIL
 * @retval GR_ERROR_INVALID_CONTEXT
 * @retval GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrSegmentTwoFingers(GR_IMAGE *image, GR_IMAGE_ARRAY **images);

/**
 * @retval GR_OK
 * @retval GR_ERROR_FAIL
 * @retval GR_ERROR_INVALID_CONTEXT
 * @retval GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrSegmentFourFingers(GR_IMAGE *image, GR_IMAGE_ARRAY **images);

/**
 * Segments the current image in multiple images, each containing a single fingerprint.
 *
 * The following code loads an image from the disk containing 2 fingerprints, segments it and extracts each segmented
 * image.
 * @code{.cpp}
 * GR_IMAGE *twoFingers;
 * GR_IMAGE_ARRAY *segmentedImages;
 * GR_TEMPLATE *tptOne, tptTwo;
 *
 * GrLoadFromFile("C:/twoFingers.png", &twoFingers);
 *
 * GrSegmentNFingers(twoFingers, 2, &segmentedImages);
 *
 * GrExtract(segmentedImages->image[0], DEFAULT, ASCII, &tptOne);
 * GrExtract(segmentedImages->image[1], DEFAULT, ASCII, &tptTwo);
 *
 * // Do something with the extracted templates
 * doSomething(tptOne, tptTwo);
 *
 * GrFreeImage(&twoFingers);
 * GrFreeImageList(&segmentedImages);
 * GrFreeTemplate(&tptOne);
 * GrFreeTemplate(&tptTwo);
 * @endcode
 *
 * @note       The GBS Fingerprint SDK library must have been previously initialized.
 * @note       A Professional License is required to use this method.
 *
 * @param[in]  image    The image to be segmented
 * @param[in]  nfingers The amount of fingerprints expected in the image
 * @param[out] images   The segmented images; this must be freed after being used by calling GrFreeImageList()
 *
 * @return     On success, `GR_OK` is returned. On failure, the appropriate error code is returned.
 *
 * @retval GR_OK
 * @retval GR_ERROR_FAIL
 * @retval GR_ERROR_INVALID_CONTEXT
 * @retval GR_ERROR_NOT_INITIALIZED
 */
DLLIMPORT GrSegmentNFingers(GR_IMAGE *image, int nfingers, GR_IMAGE_ARRAY **images);


/******************************************************************************************
 * Advanced Functions                                                                     *
 ******************************************************************************************/

/**
 * @retval GR_OK
 * @retval GR_ERROR_INVALID_CONTEXT
 * @retval GR_ERROR_INVALID_TEMPLATE
 * @retval GR_ERROR_NOT_INITIALIZED
 * @retval GR_ERROR_NULL_ARGUMENT
 * @retval GR_ERROR_PARAMETERS
 */
DLLIMPORT GrDeserializeTemplate(GR_TEMPLATE *tpt, GR_MINUTIA **minutiae, int *size);

/**
 * @retval GR_OK
 * @retval GR_ERROR_INVALID_CONTEXT
 * @retval GR_ERROR_INVALID_FILETYPE
 * @retval GR_ERROR_NOT_INITIALIZED
 * @retval GR_ERROR_NULL_ARGUMENT
 * @retval GR_ERROR_PARAMETERS
 */
DLLIMPORT GrSerializeTemplate(GR_MINUTIA *minutiae, int size, GR_TEMPLATE_FORMAT format, GR_ENCODING encoding, GR_TEMPLATE **tpt);

/**
 * @retval GR_OK
 * @retval GR_ERROR_INVALID_CONTEXT
 * @retval GR_ERROR_NOT_INITIALIZED
 * @retval GR_ERROR_NULL_ARGUMENT
 * @retval GR_ERROR_PROCESSED_IMAGE_NOT_EXTRACTED
 */
DLLIMPORT GrGetProcessedImage(GR_PROCESSED_IMAGE_TYPE type, GR_IMAGE **image);

/******************************************************************************************
 * Image Quality Analysis Functions                                                       *
 ******************************************************************************************/
DLLIMPORT GrAnalyzeImageContrast(GR_IMAGE *image, int *contrast);

DLLIMPORT GrAnalyzeImageNFIQ(GR_IMAGE *image, int *nfiq);

/******************************************************************************************
 * Twin Locked Cursor Functions                                                           *
 ******************************************************************************************/
DLLIMPORT GrTwinCompute(GR_TEMPLATE *query, GR_TEMPLATE *reference, GR_MATCH_PAIR *mpair, int size, int maxpairs);

DLLIMPORT GrTwinDirect(GR_POINT qpoint, GR_POINT *rpoint);

DLLIMPORT GrTwinReverse(GR_POINT rpoint, GR_POINT *qpoint);

/******************************************************************************************
 * GSD Functions (Griaule Spoof Detect)                                                   *
 ******************************************************************************************/
DLLIMPORT GrGSDConfigure(GR_GSD_METHOD method, char *filename);

DLLIMPORT GrGSDTest(GR_IMAGE *image);
#endif
