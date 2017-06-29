# VR Player and Monetization for App Developers

OmniVirt makes the leading player for 360 video experiences across mobile and desktop. 
Upload your 360 content to OmniVirt and serve it into your app. 

The OmniVirt advertising platform enables developers and publishers to monetize their apps with engaging VR content.
Simply integrate the OmniVirt SDK into your iOS, Android, Unity or Web application and get paid for presenting sponsored 360 video experiences to your users. Backfill your inventory with premium CPM experiences from OmniVirt’s network of advertisers. We support both 360° and 2D video ads inside VR apps.

Contact us for more info at [contact@omnivirt.com](mailto:contact@omnivirt.com).
Visit [www.omnivirt.com](https://www.omnivirt.com/) to upload content or create ad space.


## Add the OmniVirt SDK to your app

### Using CocoaPods
CocoaPods is the most conventient way to add the OmniVirt SDK to your app.
Check out [www.cocoapods.org](www.cocoapods.org) for more information.

1. Add the following line to your podfile
   <pre>
   pod 'OmniVirtSDK'
   </pre>
2. Run this in your build directory to add 
   <pre>
   $ pod install
   </pre>


## Use the OmniVirt Player

### Display your own VR content
1. Sign up for an account at [OmniVirt](www.omnivirt.com)
2. Upload your VR/360-degree photo or video at [OmniVirt](https://www.omnivirt.com/).
3. OmniVirt will assign an ID to your content as part of the upload. Copy the content ID and pass it to the VRPlayer's load method.

   <pre>
   player.load(withContentID: 0000); // Replace 0000 with your Content ID.
   </pre>

### Monetize your app with sponsored VR content

1. Sign up for an account at [OmniVirt](www.omnivirt.com)
2. Create one or more Ad Spaces for your app (for each Ad Space you can select different content and will get separate reporting)
3. Select what content to run in each Ad Space (e.g. OmniVirt's network ads)
4. Add one or more instances of the OmniVirt VRPlayer to your app (one for each Ad Space)

## Tutorials
### Add a VRPlayer programmatically
To add a VRPlayer to your view, simply create a new VRPlayer instance. You can set the player's frame to any size you like and use it in portrait or landscape mode.
   <pre>
   let vrPlayer = VRPlayer.create();
   vrPlayer.load(withContentID: 24); // Replace 24 with your Content ID
   vrPlayer.frame = self.view.frame;
   self.view.addSubview(vrPlayer);
   vrPlayer.layoutSubviews();
   </pre>

### Add an Ad Space programmatically
To add an Ad Space in your app, create a new instance of the VRAd object to your view controller.
   <pre>
   let myAd = VRAd.create(withAdSpaceID: 1000, andViewController: self, andListener: self) 
   //replace 1000 with your Ad Space ID
   </pre>
To load an ad from the network for you Ad Space call the load method
   <pre>
   myAd.load()
   </pre>
You can listen to the ad state to check when the ad is ready to display
   <pre>
   func adStatusChanged(withAd ad: VRAd, andStatus status: AdState) {
     switch (status) {
       case AdState.NONE:
         break;
       case AdState.LOADING:
         ...
       case AdState.READY:
         // Set the button into ready status. So, we can launch the ad space.
         startAdButton.setTitle("Start Ad", for: UIControlState.normal);
         ...
       case AdState.SHOWING:
         ...
       case AdState.COMPLETED:
         ...
       case AdState.FAILED:
         ...
     }
   }
   </pre>
Once the ad is ready to display you can call the show method on the ad.
    <pre>
	myAd.show(withCardboardMode: Mode.OFF)
   </pre>

### Access camera to read Cardboard QR code
Remember that on iOS 10+ you need to specify the purpose of accessing the camera.
In your Info.plist file add the property "Privacy - Camera Usage Description" and add a descriptive text such as "Used to read Cardboard QR code"

### Use Storyboard to add a VRPlayer

This tutorial shows you how to make fullscreen cardboard app within minutes.

Inside the ViewController of the sample app you will find the Player view, which subclasses VRPlayer. **If you plan to use VRPlayer in both landscape and portrait orientation, please make sure to set your controller to allows both orientation**. The gyroscope may not give you an accurate reading if the device orientation is not supported and the phone is rotated.

![alt tag](https://s3.amazonaws.com/adsoptimal-3dx-assets/manual_upload/wiki/step+1+-+Check+VRPlayer+View.png)

Try to make the VRPlayer fill the full screen by setting the vertical constraint to zero.

![alt tag](https://s3.amazonaws.com/adsoptimal-3dx-assets/manual_upload/wiki/step+2+-+Make+Player+fullscreen.png)

Replace your OmniVirt content ID and insert "player.cardboard = Mode.ON;" inside the playerLoaded() method.

![alt tag](https://s3.amazonaws.com/adsoptimal-3dx-assets/manual_upload/wiki/step+3+-+Turn+cardboard+mode+on.png)

### Result

![alt tag](https://s3.amazonaws.com/adsoptimal-3dx-assets/manual_upload/wiki/cardboard+output.png)

### Example Apps

- [Swift VR Player / Monetization](https://github.com/OmniVirt/iOS-VR-Example/tree/master/Examples/Swift/VRKitExample)
- [Objective-C VR Player / Monetization](https://github.com/OmniVirt/iOS-VR-Example/tree/master/Examples/Objective%20C/VRKitExample)
- [Cardboard QR Code Reader](https://github.com/OmniVirt/iOS-VR-Example/tree/master/Examples/Scan%20QR%20Code/VRKitExample)

# Questions?

Please email us at [contact@omnivirt.com](mailto:contact@omnivirt.com)
