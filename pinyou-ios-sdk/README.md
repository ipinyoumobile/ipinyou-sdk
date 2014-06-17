品友iOS SDK集成指南
===

----

### 一.Pinyou 固定位广告iOS SDK集成指南

#### 1. 获取广告位ID

注册自己的App并获取广告位ID`adUnitId`

#### 2. iOS SDK配置

1. 在项目中添加libPinyou.a，*.h和Pinyou.bundle文件。
2. 在Targets添加对libPinyou.a的依赖。
3. 在Targets中添加以下Framework

	* SystemConfiguration.framework
	* ImageIO.framework
	* CoreLocation.framework
	* CoreTelephony.framework
	* AdSupport.framework
	* MobileCoreServices.frameword

####3. 广告展示代码


####3.1 配置`AppDelegate.m`


初始化SDK,添加代码如下:

```
	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
 	[PYAdRequest initSDKWithVersion:(NSString *)SDKVersion];
}
```
#####3.2 快速展示广告

直接调用`Pinyou`的类方法

`[Pinyou showDefaultTopBannerView];`
	
#####3.3 自定义展示广告

需要自定义创建`PYBannerView`对象

```
    PYBannerView *bannerView = [[[PYBannerView alloc] initWithFrame:rect] autorelease];
    bannerView.delegate = self;
    [bannerView setAdUnitId:adUnitId];
    [layerView addSubview:bannerView];
    
    [bannerView loadAdInfo];
```
更多自定义方法请参考`PYBannerViewDelegate.h`文件.

**如果想自定义打开点击地址效果,需要通知品友,为相应广告位开通此功能**	

----

###二转化统计SDK集成指南

#### 1.导入SDK

- 下载pinyou-ios-sdk.zip并解压缩

- 导入相关文件
> 所需文件：`libPinyouSDK.a` 和 `PYConversion.h`。在工程目录结构中，右键选择`Add->Existing Files…`，选择这两个文件。或者将这两个文件拖入XCode工程目录结构中，在弹出的界面中勾选`Copy items into destination group's folder(if needed)`, 并确保`Add To Targets`勾选相应的target。

- 配置
>添加依赖框架(Framework)和编译器选项
`TARGETS`-->`Build Phases`-->`Link Binary With Libraries`--> `+` -->`libz.dylib`,`SystemConfiguration.framework`,`Frameworks/CoreTelephony.framework`

- 添加代码
当用户首次启动应用时，向品友服务器发送用户信息，在appDelegate.m相应方法中添加代码如下

```
[[PYConversion defaultManager] noticeConversionWithParamA:@"FJD.SLfjs" conversionType:PY_DownLoad];
```

说明：

1. 需要传入两个参数：`paramA`是由品友提供的关于广告主信息加密后的a参数，在下载SDK页面或者线下提供。`conversionType`为转化类型,当转化目标为下载 时,传入`Download`. 当品友接收到参数时，输出成功日志` Sending request to Pinyou Completed!!`,否则打印失败日志` Sending request to Pinyou has error!!`

#### 二.技术支持

请发邮件至 [mobile-core@ipinyou.com](mailto:mobile-core@ipinyou.com),我们会快回复您。
