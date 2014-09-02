##Pinyou Android SDK集成指南

----

### 一.Android 固定位广告 SDK集成流程

####1. 获取广告位ID
注册自己的App并获取广告位ID`AdUnit`

####2. 导入Android SDK jar包

下载并导入libPinyou.jar
``` java
AdView.getVersion():"PYSDK_V1.5"
(若debug版本:"PYSDK_V1.5debug")
```


####3. 添加用户权限

``` xml
<!-- 添加用户权限 --><!-- 连接网络权限INTERNET ,用于请求广告(必须) --><uses-permission android:name="android.permission.INTERNET" /><!-- 读取手机基本信息权限READ_PHONE_STATE、BLUETOOTH等,用于精确统计用户的机型、标识等信息(必须)--><uses-permission android:name="android.permission.READ_PHONE_STATE" />
<uses-permission android:name="android.permission.BLUETOOTH" /><!-- 读取网络信息权限ACCESS_NETWORK_STATE,用于识别gprs网络的接入点的情况(必须) --><uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" /><!-- 获取用户地理信息权限,用于帮助精确统计开发者的程序发布之后的用户分布情况 --><uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" /> 
<uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" /><uses-permission android:name="android.permission.ACCESS_LOCATION_EXTRA_COMMANDS" /><!--获得当前wifi的状态--> 
<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" /><!--拨打电话权限 --><uses-permission android:name="android.permission.CALL_PHONE" /> 
<!--向SD卡中写入缓存 -->
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />```

####4. 配置广告展示代码

#####4.1 在要展示广告的Activity的`OnCreate`方法放置以下代码

``` java
adView = new AdView(this, "hA.3Y",new AdSize(w,h));
//adView.noCloser = true;//显示关闭按钮
LinearLayout layout = (LinearLayout) findViewById(R.id.linearLayout);
layout.addView(adView,0);
adView.loadAd();
```

#####4.2 广告展现的回调方法
  
需要展示广告主的Activity实现AdsPinyouListener接口,并覆盖如下方法

``` java
	/* 广告关闭按钮回调方法
	 * return true关闭广告,false不关闭
	 */
	@Override
	public boolean onAdClosed(){
		logToast(this,"You can buy the pro edition to hide the Ad!!");
		return false;
	}
	/* 广告点击回调方法
	 */
	@Override
	public void onAdClicked() {
		logToast(this,"click Ad!!");
	}
	
	/*
	 *点击广告时自定义是通过浏览器打开或是通过app内部webview打开
	 *注意:使用此项功能需要通知品友.在服务器商进行设置
	 *return 如果为true为外部浏览器打开
	 */
	@Override
	public boolean onAdOpenInBrowser(String url) {
		logToast(this,url);
		return true;
	}
	
	/*
	 *广告加载失败时回调接口
	 *return 
	 *	 */
	@Override
	public boolean onAdShowFailed() {
		Tools.d("ad load faild");
		return false;
	}
``` 

#####4.3 释放资源
开发者需要在启动的第一个Activity的onDestroy方法中调

``` java
/** Called before the activity is destroyed. **/
  	@Override
  	public void onDestroy() {
    		// Destroy the AdView.
		if (adView != null) {
    			adView.destroy();
    		}
    		super.onDestroy();
  	}
```

#####4.4 开机广告支持
``` java

adView = new AdView(this, "tn.RR", new AdSize(320, 171));
		
	adView.noCloser = true;
	adView.isBootScreen = true;
	adView.setAdsPinyouListener(this);
		
	adView.loadAd();
	Bitmap bitmap = adView.getBootScreenDrawable();
	    
```
----

### 二. 转化统计SDK集成流程

#### 1.导入SDK

##### 1.1下载libPinyou.jar

##### 1.2导入相关文件

 下载最新版SDK的 libPinyou.jar，导入到本地工程libs子目录下。
``` java
AdConversionFactory.getVersion():"PYSDK_V1.5"
(若debug版本:"PYSDK_V1.5debug")
```

##### 1.3.配置
>Eclipse用户右键工程根目录，选择Properties -> Java Build Path -> Libraries，然后点击Add External JARs... 选择指向jar的路径，点击OK，即导入成功。

**配置 AndroidManifest.xml**

```
<manifest……>
<application ……>
……
<activity ……/>

</application>
<uses-permission android:name="android.permission.READ_PHONE_STATE" />
    <uses-permission android:name="android.permission.BLUETOOTH" />
    <uses-permission android:name="android.permission.INTERNET" />
    <uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
    <uses-permission android:name="android.permission.ACCESS_FINE_LOCATION"/>
    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>
    <uses-sdk
        android:minSdkVersion="9"
        android:targetSdkVersion="18" />
</manifest>

```
#### 2.支持Android IDFA(可选)

品友的sdk中支持传送Advertising ID数据，便于未来更准确的向用户投放广告。获取此ID需要满足以下条件
    
 - Android sdk 需要包含  Google Play services 4.0+ ,advertising ID APIs 
 - 用户设备需要安装GooglePlay服务

> 配置Google Play Service SDK：
    
> 参考[Set up Google Play Service SDK](http://developer.android.com/google/play-services/setup.html)
 
#####2.1 安装Google Play Service SDK
 
 在IDE中打开`SDK Manager`,滑动到包列表的底部，，展开`Extras`并选择安装`Google Play Service`。此时，Google Play Service 已经保存到`<android-sdk>/extras/google/google_play_services/`中。
 
######2.2 项目中依赖`Google Play Service`项目包
 
 如果使用Eclipse，导入Google Play Service 项目到工作区，Click File > Import, select Android > Existing Android Code into Workspace, and browse to the copy of the library project to import it.

######2.3 配置 AndroidManifest.xml
 
 
```
 <application ...>
 ...
 <meta-data android:name="com.google.android.gms.version"
           android:value="@integer/google_play_services_version" />
 </application>
 
```

#### 三.添加代码

当用户首次打开应用程序时，向品友服务器发送用户信息，添加代码如下

```
AdConversion pyConversion = AdConversionFactory.createAdConversion(getApplicationContext(), "a5.Yo", "1234");
pyConversion.noticeToPinyou();
```

说明：

1. `AdConversionFactory. createAdConversion(Context context,String paramA,String conversionType,String flag)`需要传入几个参数：其中`paramA`是由品友提供的关于广告主公司信息加密后的a参数。`ConversionType`参数：转化目标（在优驰系统中生成的转化目标ID）;`flag`表示品友传递的标识符,此参数为可选参数。(这些都可联系对口的业务人员获取)
2. 关于Advertising ID的获取，品友SDK中会对用户的设备判断是否安装了Google Play服务和满足版本要求，如果满足条件才去获取此设备的AdvertisingID,否则不执行相关代码获取。
3. 订单跟踪参数进阶。(详细可咨询接口人员)：
`
AdConversion pyConversion = AdConversionFactory.createAdConversion(getApplicationContext(), "a5.Yo", "1234");
pyConversion.setOrderNo("1");
pyConversion.noticeToPinyou();
`
4. 如何确认上报成功：在logcat中‘debug’级能看到字样如：`PYSDK_V1.5 : send the convertion: , , , to Pinyou SUCCESS!!`

5. 针对“Download”这个转化目标仅在第一次启动时会上报数据，之后app再启动是不会再上报数据的



_proguard防二次混淆注意事项：
由于libPinyou.jar采用proguard混淆过，为了防止二次混淆，请按如下配置：
proguard-project.txt  最后加上_

```
-libraryjars <libPinyou.jar Path> 
-keep class com.ipinyou.sdk.ad.** {*; }
-keep class org.OpenUDID.** {*; }
```
[说明: `<libPinyou.jar Path>`:需配置能找到libPinyou.jar的路径     
`
-keep class com.ipinyou.sdk.**{*;}`    :包名 com.ipinyou.sdk 下的所有class 文件不参与混淆]

`-keep class org.OpenUDID.**{*;}`    :包名 org.OpenUDID 下的所有class 文件不参与混淆]


###联系品友**如果您有任何问题或疑问,请及时联系品友移动组。我们将在第一时间做出回应。**** Email:mobile-core@ipinyou.com **
