###品友Android统计SDK集成指南

----
#### 一.导入SDK

##### 1.下载pinyou-android-sdk.zip并解压缩

##### 2.导入相关文件

 下载最新版SDK的zip包，将其中的libs 文件夹合并到本地工程libs子目录下。

##### 3.配置
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
##### 4.支持Android IDFA(可选)

品友的sdk中支持传送Advertising ID数据，便于未来更准确的向用户投放广告。获取此ID需要满足以下条件
	
 - Android sdk 需要包含  Google Play services 4.0+ ,advertising ID APIs 
 - 用户设备需要安装GooglePlay服务

###### 配置Google Play Service SDK：
	
参考[Set up Google Play Service SDK](http://developer.android.com/google/play-services/setup.html)
 
######4.1 安装Google Play Service SDK
 
 在IDE中打开`SDK Manager`,滑动到包列表的底部，，展开`Extras`并选择安装`Google Play Service`。此时，Google Play Service 已经保存到`<android-sdk>/extras/google/google_play_services/`中。
 
######4.2 项目中依赖`Google Play Service`项目包
 
 如果使用Eclipse，导入Google Play Service 项目到工作区，Click File > Import, select Android > Existing Android Code into Workspace, and browse to the copy of the library project to import it.

######4.3 配置 AndroidManifest.xml
 
 
```
 <application ...>
 ...
 <meta-data android:name="com.google.android.gms.version"
           android:value="@integer/google_play_services_version" />
 </application>
 
```

#### 5.添加代码

当用户首次打开应用程序时，向品友服务器发送用户信息，添加代码如下

```
AdConversion pyConversion = new AdConversion(getApplicationContext());
pyConversion.noticeToPinyou("FDSLFNS-*dsL",ConversionType.Download);
```

说明：

1. 需要传入两个参数：`paramA`是由品友提供的关于广告主信息加密后的a参数，在下载SDK页面提供。`ConversionType`参数：转化目标` ConversionType{
        FirstRun,Download,Pay,Register
	}`
2. 关于Advertising ID的获取，品友SDK中会对用户的设备判断是否安装了Google Play服务和满足版本要求，如果满足条件才去获取此设备的AdvertisingID,否则不执行相关代码获取。


#### 二.技术支持

请发邮件至 [mobile-core@ipinyou.com](mailto:mobile-core@ipinyou.com),我们会快回复您。