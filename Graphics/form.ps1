$OpenFileDialog1_FileOk = {
    #$Label1.Text = $OpenFileDialog1.FileName;
}
$Form1_Load = {
}
$Button1_Click = {
    $OpenFileDialog1.ShowDialog();
}
Add-Type -AssemblyName System.Windows.Forms
. (Join-Path $PSScriptRoot 'form.designer.ps1')
$Form1.ShowDialog()