##Pinyou 固定位广告Android SDK集成指南

----

### 一.Android SDK集成流程

####1. 获取广告位ID
注册自己的App并获取广告位ID`AdUnit`

####2. 导入Android SDK jar包

* 在项目的根目录新建libs文件夹(可选)。
* 右键单击新建的libs文件夹,在弹出窗口中,选择Import -> General -> File System,完成操作 后,点击“Next”按钮,进入下一步。
* 找到Pinyou_Android_SDK/libs文件夹路径,右侧选中芒果SDK (Pinyou_SDK_Android.jar),选中Create selected folders only
* 选中libs文件夹中所有jar包,单击右键->Build Path->Add to Build Path


####3. 添加用户权限

``` xml
<!-- 添加用户权限 -->
<uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" />
<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />

####4. 配置广告展示代码

#####4.1 在要展示广告的Activity的`OnCreate`方法放置以下代码

``` java
adView = new AdView(this, "hA.3Y");//不需要设置广告位尺寸,会根据屏幕自适应
//adView.noCloser = true;//显示关闭按钮
LinearLayout layout = (LinearLayout) findViewById(R.id.linearLayout);
layout.addView(adView,0);
adView.loadAd();
```

#####4.2 广告关闭按钮的回调方法
  
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

----

### 二. 转化统计SDK集成流程

#### 1.导入SDK

##### 1.1下载pinyou-android-sdk.zip并解压缩

##### 1.2导入相关文件

 下载最新版SDK的zip包，将其中的libs 文件夹合并到本地工程libs子目录下。

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
    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>
    <uses-sdk
        android:minSdkVersion="9"
        android:targetSdkVersion="18" />
</manifest>

```
#### 2.支持Android IDFA

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
AdConversion pyConversion = AdConversionFactory.createAdConversion(getApplicationContext(), "FD.DFS", ConversionType.Download);
pyConversion.noticeToPinyou();
```

说明：

1. 需要传入两个参数：`paramA`是由品友提供的关于广告主信息加密后的a参数，在下载SDK页面提供。`ConversionType`参数：转化目标` ConversionType{
        Download,Pay,Register
    }`
2. 关于Advertising ID的获取，品友SDK中会对用户的设备判断是否安装了Google Play服务和满足版本要求，如果满足条件才去获取此设备的AdvertisingID,否则不执行相关代码获取。



###联系品友