##Installing the SDK

Analysis SDK includes necessary tools to:
 
1. Track your application
2. Push notification
3. Schedule local notification
4. Internal A.D. which lunch before app start

In order to integrate SDK to your application, follow these steps.

1. Download Analysis iOS SDK (or clone it in your project as a git submodule).
2. Drop folder `MobileSDK.framework` to your project under Xcode
4. Select your project in the Project Navigator
5. Select the **Build Phases** tab
6. Open **Link Binaries With Libraries** expander
7. Click the **+** button
8. Select CoreTelephony.framework and Corelocation.framework select **Required**
10. *(optional)* Drag and drop the added framework to the **Frameworks** group
11. In your application delegate, `#import <MobileSDK/MobileSDK.h>`


**Note:** Make sure you use App Key (found under Management -> Applications) and not API Key or App ID. Entering API Key or App ID will not work.


It should finally look like this:

<pre class="prettyprint">
#import <MobileSDK/MobileSDK.h>  // newly added line
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
[MobileSDK start:@"TYPE_HERE_YOUR_APP_KEY_GENERATED_IN_ADMIN_DASHBOARD" withHost:@"http://TYPE_HERE_URL_WHERE_API_IS_HOSTED" andAppStoreID:@"YOUR_App_Apple_ID"]; // newly added line
// your code
}
</pre>

It you want to have App control in admin panel:

<pre class="prettyprint">
#import <MobileSDK/MobileSDK.h>  // newly added line
- (void)applicationWillEnterForeground:(UIApplication *)application
{
 [MobileSDK appControlAction:YES];
// your code
}
</pre>

It you want to have notification and local notification:

<pre class="prettyprint">
#import <MobileSDK/MobileSDK.h> // newly added line
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
[MobileSDK start:@"TYPE_HERE_YOUR_APP_KEY_GENERATED_IN_ADMIN_DASHBOARD" withHost:@"http://TYPE_HERE_URL_WHERE_API_IS_HOSTED" andAppStoreID:@"YOUR_App_Apple_ID"]; // newly added line
  [[UIApplication sharedApplication] registerForRemoteNotificationTypes:(UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound)];
	// Clear application badge when app launches
	application.applicationIconBadgeNumber = 0;
// your code
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)devToken {
    
	
#if !TARGET_IPHONE_SIMULATOR
	// Check what Notifications the user has turned on.  We registered for all three, but they may have manually disabled some or all of them.
	NSUInteger rntypes = [[UIApplication sharedApplication] enabledRemoteNotificationTypes];
	// Set the defaults to disabled unless we find otherwise...
	NSString *pushBadge = (rntypes & UIRemoteNotificationTypeBadge) ? @"enabled" : @"disabled";
	NSString *pushAlert = (rntypes & UIRemoteNotificationTypeAlert) ? @"enabled" : @"disabled";
	NSString *pushSound = (rntypes & UIRemoteNotificationTypeSound) ? @"enabled" : @"disabled";
	
    // Prepare the Device Token for Registration (remove spaces and < >)
	NSString *deviceToken = [[[[devToken description]
                               stringByReplacingOccurrencesOfString:@"<"withString:@""]
                              stringByReplacingOccurrencesOfString:@">" withString:@""]
                             stringByReplacingOccurrencesOfString: @" " withString: @""];
    
    
    
    [MobileSDK trackDeviceToken:deviceToken pushBadge:pushBadge pushAlert:pushAlert pushSound:pushSound];
    
#endif
}

/**
 * Failed to Register for Remote Notifications
 */
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
	
#if !TARGET_IPHONE_SIMULATOR
	
	
#endif
}

/**
 * Remote Notification Received while application was open.
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
	
#if !TARGET_IPHONE_SIMULATOR
   
	
#endif
}
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification{
    
#if !TARGET_IPHONE_SIMULATOR
    
    
#endif
}

</pre>

Note: Before upgrading to a new SDK, do not forget to remove the existing, older SDK from your project.

