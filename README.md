# OmniVirt VR Player: 360° Video Player for iOS

![Screenshot](https://github.com/OmniVirt/OmniVirtVRPlayer-iOS-Example/raw/master/Screenshots/screenshot.jpg)

**OmniVirt** makes the leading player for 360° video experiences across mobile and desktop. Upload your 360° content to OmniVirt and serve it into your app with few easy steps.


Visit [omnivirt.com](https://omnivirt.com/) to upload your VR content. Contact us for more info at [contact@omnivirt.com](mailto:contact@omnivirt.com).

# Add the OmniVirt SDK to your app

## Using CocoaPods

CocoaPods is the most conventient way to add the OmniVirt SDK to your app. Check out [www.cocoapods.org](https://www.cocoapods.org) for more information.

- Add the following line to your podfile.
```
pod 'OmniVirtSDK'
```
- Install dependencies.
```
$ pod install
```
- Open the newly created `.xcworkspace`

# Usage

**OmniVirt VR Player** for iOS provides you a really easy way to embed 360° content in your iOS application with just few lines of code.

## Get Started

1. **Sign up** for an account at [OmniVirt](https://www.omnivirt.com)
2. **Upload** your VR / 360° photo or video on [OmniVirt](https://www.omnivirt.com/).
3. Keep the **Content ID** assigned to your content for further use.

Now the content is ready. There are two methods that you can use OmniVirt VR Player to play your VR content on your application.

## Method 1: Launch a Fullscreen VR Player

This method lets you play a VR content with just a single line of code !

### Swift

```swift
import OmniVirtSDK
```
```swift
let fsplayer = FullscreenVRPlayer.launch(withContentID: CONTENT_ID, // Replace with your Content ID
                          andAutoplay: true,
                          andCardboardMode: Mode.Off
                          )
fsplayer.modalPresentationStyle = .fullScreen
self.present(fsplayer, animated: true) {
}
```

### Objective-C

```objc
import <OmniVirtSDK>
```
```objc
[FullscreenVRPlayer launchWithContentID:CONTENT_ID  // Replace with your Content ID
                    andAutoplay:YES
                    andCardboardMode:ModeOff]
```

And ... done ! That's all !

### Extra: Earn Money
Would like to earn money from your 360° content? You can create an **Ad Space** on [OmniVirt](www.omnivirt.com) and pass the **Ad Space ID** acquired to the command like shown below to enable ad on the player.

#### Swift

```swift
FullscreenVRPlayer.launch(withContentID: CONTENT_ID, // Replace with your Content ID
                          andAutoplay: true,
                          andCardboardMode: .Off,
                          andAdSpaceID: ADSPACE_ID  // Replace with your Ad Space ID
                          )
```

#### Objective-C

```objc
[FullscreenVRPlayer launchWithContentID:CONTENT_ID  // Replace with your Content ID
                    andAutoplay:YES
                    andCardboardMode:ModeOff
                    andAdSpaceIDNumber:[NSNumber numberWithInt: AD_SPACE_ID]] // Replace with your Ad Space ID
```

Once it is set up correctly, user will sometime see an ad among the player and that will turn into your revenue !

### Player Callback

Any change on the player could be detected by implementing `VRPlayerDelegate` interface inside the **caller class**. Here is the example.

```swift
class ViewController: UIViewController, VRPlayerDelegate {

    ...
    
    func play() {
        let player = FullscreenVRPlayer.launch(withContentID: 24,
                                               andAutoplay: true,
                                               andCardboardMode: .Off
                                              )
        player.delegate = self
    }
    
    /**
     * Called when VR Player is loaded
     **********************************/
    func playerLoaded(_ player: VRPlayer, withMaximumQuality maximum:Int, andCurrentQuality current:Quality, andCardboardMode mode:Mode) {
    }
    
    /**
     * Called when VR Player has started playing
     ********************************************/
    func playerStarted(_ player: VRPlayer) {
    }
    
    /**
     * Called when VR Player is paused
     **********************************/
    func playerPaused(_ player: VRPlayer) {
    }
    
    /**
     * Called when VR Player has finished playing
     *********************************************/
    func playerEnded(_ player: VRPlayer) {
    }
    
    /**
     * Called when video has been skipped for the next one
     ******************************************************/
    func playerSkipped(_ player: VRPlayer) {
    }
    
    /**
     * Called when video duration has been changed
     *
     *   value - new duration in seconds
     **********************************************/
    func playerDurationChanged(_ player: VRPlayer, withValue value:Double) {
    }
    
    /**
     * Called when video progress has been changed
     *
     *   value - current progress in seconds
     **********************************************/
    func playerProgressChanged(_ player: VRPlayer, withValue value:Double) {
    }
    
    /**
     * Called when video has been buffered
     *
     *   bufferLength - buffer length in seconds
     ********************************************/
    func playerBufferChanged(_ player: VRPlayer, withValue bufferLength:Double) {
    }
    
    /**
     * Called when video has been seeked
     *
     *   value - seeked position in second
     *****************************************/
    func playerSeekChanged(_ player: VRPlayer, withValue value:Double) {
    }
    
    /**
     * Called when Cardboard mode has been changed
     *
     *   mode - new Cardboard mode (ON, OFF)
     **********************************************/
    func playerCardboardChanged(_ player: VRPlayer, withMode mode:Mode) {
    }
    
    /**
     * Called when volume level has been changed
     *
     *   volume - new volume level
     ********************************************/
    func playerAudioChanged(_ player: VRPlayer, withLevel volume:Double) {
    }
    
    /**
     * Called when video quality has been changed
     *
     *  quality - new video quality (QualitySD, QualityHD, QualitySHD and Quality4K)
     ******************************************************************************/
    func playerQualityChanged(_ player: VRPlayer, withQuality quality:Quality) {
    }
    
    /**
     * Called when VR player has been expanded fullscreen
     *****************************************************/
    func playerExpanded(_ player: VRPlayer) {
    }    

    /**
     * Called when VR player has been restored to embedded size
     ***********************************************************/
    func playerCollapsed(_ player: VRPlayer) {
    }
    
    /**
     * Called when video angle in y-axis has been changed
     *
     *   latitude - new angle in degree
     *****************************************************/
    func playerLatitudeChanged(_ player: VRPlayer, withLatitude latitude:Double) {
    }    

    /**
     * Called when video angle in x-axis has been changed
     *
     *   longitude - new angle in degree
     *****************************************************/
    func playerLongitudeChanged(_ player: VRPlayer, withLongitude longitude:Double) {
    }
    
    /**
     * Called when video scene has been switched
     *
     *   sceneName - the name of new scene
     *   history - list of scenes navigated
     *****************************************/
    func playerSwitched(_ player: VRPlayer, withScene sceneName: String, withHistory history: [String]) {
    }

}
```


## Method 2: Embed a VR Player on a View with `VRPlayer`
 
OmniVirt VR Player also provides you an UIView that allows you to embed a VR Player on your View.

### Use Storyboard to add a VRPlayer
 
1. Place a new UIView and assign Class as `VRPlayer` with the module `OmniVirtSDK`

![Screenshot](https://github.com/OmniVirt/OmniVirtVRPlayer-iOS-Example/raw/master/Screenshots/ssstoryboard.png)

2. Create an IBOutlet and link it to a created VRPlayer UIView
```swift
@IBOutlet weak var player: VRPlayer!
```

You can now make use of VRPlayer through `player` variable.

### Add a VRPlayer programmatically

You can also add a player programatically with the following code snippet.

```swift
let player = VRPlayer.create()
player.load(withContentID: CONTENT_ID) // Replace with your Content ID
player.frame = view.frame
view.addSubview(player)
player.layoutSubviews()
```

### Play Content

To start playing your VR content, add the following snippet to your view controller and replace `CONTENT_ID` with your VR content's.

```swift
// Register a callback
player.delegate = self
// Load a content
player.load(contentID: CONTENT_ID) // Replace with your Content ID
// Set player parameter
player.cardboard = .Off
```

Player callback could also be retrieved by the same approach as sample above.

To support autoplay content call `play()` in `playerLoaded` callback
```swift
func playerLoaded(_ player: VRPlayer, withMaximumQuality maximum:Int, andCurrentQuality current:Quality, andCardboardMode mode:Mode) {
    player.play()
}
```

# QR Code for Cardboard Alignment

You can also launch QR Code scanner to calibrate Cardboard by scanning a QR Code comes along with the Cardboard. To do so, call this following function.

```swift
VRQRScannerViewController.launchCardboardQRScanner(delegate: self)
```


# Questions?

Please feel free to email us at [contact@omnivirt.com](mailto:contact@omnivirt.com) !
