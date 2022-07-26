# 利用Arduino接收紅外線訊號，並重新發送

## 目錄：
*[背景](##背景)
*[參考與引用資料](##參考與引用資料)
*[過程](##過程)
*[程式庫安裝](###程式庫安裝)
*[解碼](###解碼)
*[發送訊號](###發送訊號)

## 背景
最近老師買了一隻可遙控的機械狗，其遙控的方式為：
`「利用廠商附的遙控器，將射出紅外線(IR)訊號，機械狗上的接收器接收到訊號並解碼成功後，就會做出相對應之動作。`
老師希望我們改從Arduino發送IR訊號。此題目有樂趣的地方在於：	
`這隻機械狗的IR 傳輸協定是廠商自己寫的，不是其他已經的協定(例如：Sony、NEC)。`
所以此文章是分享我解決這個問題的方法，由於我才剛寫程式一年，如果其他前輩有意願給予建議的也歡迎指教。

## 參考與引用資料
* https://ruten-proteus.blogspot.com/2018/11/ir01-decode-ir-remote-value.html
* https://ruten-proteus.blogspot.com/2019/03/ir03-transmitting-ir.html
* https://ruten-proteus.blogspot.com/2018/12/ir02-NEC-PhilipsRC6-protocol-introduction.html
* https://github.com/Arduino-IRremote/Arduino-IRremote/releases

## 過程
### 程式庫安裝
    去上面GitHub網站裡下載程式庫"Arduino-IRremote"的壓縮檔，
    
    解壓縮後放到Arduino下的libraries資料夾(C:\Users\User\Documents\Arduino\libraries)
![](https://github.com/JuniSmell/Use-IRremote-to-receive-signal-and-transmite/blob/main/picture/download_library.PNG)
![](https://github.com/JuniSmell/Use-IRremote-to-receive-signal-and-transmite/blob/main/picture/install_library.PNG)
### 解碼
![](https://github.com/JuniSmell/Use-IRremote-to-receive-signal-and-transmite/blob/main/picture/receive_signal.jpg)

    開啟程式庫裡面的範例，裡面有一個「ReceiveDump」，打開並加載進Arduino面板後，即可開始進行解碼。(預設的接收接腳為Pin 2)。
![](https://github.com/JuniSmell/Use-IRremote-to-receive-signal-and-transmite/blob/main/picture/open_receiveDump.PNG)

    打開序列埠監控視窗，裡面會有各種數據，由於我們沒有辦法找出protocol，所以我們要直接從rowData下手
    ，我是直接採用下面的uint16_t rawData[17]裡的數據。
    注意裡頭有一個9 bits，這個數字待會會用。
![](https://github.com/JuniSmell/Use-IRremote-to-receive-signal-and-transmite/blob/main/picture/row.PNG)

### 發送訊號
![](https://github.com/JuniSmell/Use-IRremote-to-receive-signal-and-transmite/blob/main/picture/transmit_signal.jpg)

    接下來打開demo檔，中間的就是所收集的rawData(注意有四個功能的數據很特別，後面解釋)。
    最下面則是負責發送訊號的函數IrSender.sendRaw(名稱、長度、前面提到的9 bits)。
    (發射IR訊號時，預設接腳為Pin 3)
    ** 有四個功能(前進、後腿進、後腿退、立正)的傳輸方式跟其他功能不同，沒辦法直接傳一次訊號就成功，
    我一時間也抓不出規律與解決方法，最後的解法是收集十組數據，然後直接一次傳出去。

