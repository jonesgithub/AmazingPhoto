#import <UIKit/UIKit.h>
#import "CPPickerView.h"


typedef enum {
    GPUIMAGE_SATURATION,
    GPUIMAGE_CONTRAST,
    GPUIMAGE_BRIGHTNESS,
    GPUIMAGE_EXPOSURE,
    GPUIMAGE_RGB,
    GPUIMAGE_HUE,
    GPUIMAGE_MONOCHROME,
    GPUIMAGE_FALSECOLOR,
    GPUIMAGE_SHARPEN,
    GPUIMAGE_UNSHARPMASK,
    GPUIMAGE_TRANSFORM,
    GPUIMAGE_TRANSFORM3D,
    GPUIMAGE_CROP,
	GPUIMAGE_MASK,
    GPUIMAGE_GAMMA,
    GPUIMAGE_TONECURVE,
    GPUIMAGE_HIGHLIGHTSHADOW,
    GPUIMAGE_HAZE,
    GPUIMAGE_SEPIA,
    GPUIMAGE_AMATORKA,
    GPUIMAGE_MISSETIKATE,
    GPUIMAGE_SOFTELEGANCE,
    GPUIMAGE_COLORINVERT,
    GPUIMAGE_GRAYSCALE,
    GPUIMAGE_HISTOGRAM,
    GPUIMAGE_THRESHOLD,
    GPUIMAGE_ADAPTIVETHRESHOLD,
    GPUIMAGE_PIXELLATE,
    GPUIMAGE_POLARPIXELLATE,
    GPUIMAGE_POLKADOT,
    GPUIMAGE_CROSSHATCH,
    GPUIMAGE_SOBELEDGEDETECTION,
    GPUIMAGE_PREWITTEDGEDETECTION,
    GPUIMAGE_CANNYEDGEDETECTION,
    GPUIMAGE_XYGRADIENT,
    GPUIMAGE_HARRISCORNERDETECTION,
    GPUIMAGE_NOBLECORNERDETECTION,
    GPUIMAGE_SHITOMASIFEATUREDETECTION,
    GPUIMAGE_BUFFER,
    GPUIMAGE_SKETCH,
    GPUIMAGE_TOON,
    GPUIMAGE_SMOOTHTOON,
    GPUIMAGE_TILTSHIFT,
    GPUIMAGE_CGA,
    GPUIMAGE_POSTERIZE,
    GPUIMAGE_CONVOLUTION,
    GPUIMAGE_EMBOSS,
    GPUIMAGE_KUWAHARA,
    GPUIMAGE_VIGNETTE,
    GPUIMAGE_GAUSSIAN,
    GPUIMAGE_GAUSSIAN_SELECTIVE,
    GPUIMAGE_FASTBLUR,
    GPUIMAGE_BOXBLUR,
    GPUIMAGE_MEDIAN,
    GPUIMAGE_BILATERAL,
    GPUIMAGE_SWIRL,
    GPUIMAGE_BULGE,
    GPUIMAGE_PINCH,
    GPUIMAGE_SPHEREREFRACTION,
    GPUIMAGE_GLASSSPHERE,
    GPUIMAGE_STRETCH,
    GPUIMAGE_DILATION,
    GPUIMAGE_EROSION,
    GPUIMAGE_OPENING,
    GPUIMAGE_CLOSING,
    GPUIMAGE_PERLINNOISE,
    GPUIMAGE_VORONI,
    GPUIMAGE_MOSAIC,
    GPUIMAGE_LOCALBINARYPATTERN,
    GPUIMAGE_DISSOLVE,
    GPUIMAGE_CHROMAKEY,
    GPUIMAGE_ADD,
    GPUIMAGE_DIVIDE,
    GPUIMAGE_MULTIPLY,
    GPUIMAGE_OVERLAY,
    GPUIMAGE_LIGHTEN,
    GPUIMAGE_DARKEN,
    GPUIMAGE_COLORBURN,
    GPUIMAGE_COLORDODGE,
    GPUIMAGE_SCREENBLEND,
    GPUIMAGE_DIFFERENCEBLEND,
	GPUIMAGE_SUBTRACTBLEND,
    GPUIMAGE_EXCLUSIONBLEND,
    GPUIMAGE_HARDLIGHTBLEND,
    GPUIMAGE_SOFTLIGHTBLEND,
    GPUIMAGE_OPACITY,
    GPUIMAGE_CUSTOM,
    GPUIMAGE_UIELEMENT,
    GPUIMAGE_FILECONFIG,
    GPUIMAGE_FILTERGROUP,
    GPUIMAGE_FACES,
    GPUIMAGE_NUMFILTERS
} GPUImageShowcaseFilterType; 


@interface ShowcaseFilterViewController : UIViewController <GPUImageVideoCameraDelegate,CPPickerViewDataSource, CPPickerViewDelegate>
{
    //GPUImageVideoCamera *videoCamera;
    GPUImageStillCamera *videoCamera;
    GPUImageOutput<GPUImageInput> *filter;
    GPUImagePicture *sourcePicture;
    GPUImageShowcaseFilterType filterType;
    GPUImageUIElement *uiElementInput;
    
    GPUImageFilterPipeline *pipeline;
    UIView *faceView;
    
    CIDetector *faceDetector;
    
    IBOutlet UISwitch *facesSwitch;
    IBOutlet UILabel *facesLabel;
    __unsafe_unretained UISlider *_filterSettingsSlider;
    BOOL faceThinking;
    
    UIBarButtonItem *photoCaptureButton;
    NSArray *mEffectsListData;
}


@property(readwrite, unsafe_unretained, nonatomic) IBOutlet UISlider *filterSettingsSlider;
@property(nonatomic,retain) CIDetector*faceDetector;
// Initialization and teardown
- (id)initWithFilterType:(GPUImageShowcaseFilterType)newFilterType;
- (void)setupFilter;
- (void)willOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer;
// Filter adjustments
- (IBAction)updateFilterFromSlider:(id)sender;
- (void)GPUVCWillOutputFeatures:(NSArray*)featureArray forClap:(CGRect)clap
                 andOrientation:(UIDeviceOrientation)curDeviceOrientation;
-(IBAction)facesSwitched:(id)sender;

- (IBAction)takePhoto:(id)sender;
@end