$Form1 = New-Object -TypeName System.Windows.Forms.Form
[System.Windows.Forms.Button]$Button1 = $null
function InitializeComponent
{
$Button1 = (New-Object -TypeName System.Windows.Forms.Button)
$Form1.SuspendLayout()
#
#Button1
#
$Button1.Location = (New-Object -TypeName System.Drawing.Point -ArgumentList @([System.Int32]37,[System.Int32]43))
$Button1.Name = [System.String]'Button1'
$Button1.Size = (New-Object -TypeName System.Drawing.Size -ArgumentList @([System.Int32]301,[System.Int32]103))
$Button1.TabIndex = [System.Int32]0
$Button1.Text = [System.String]'Click here'
$Button1.UseCompatibleTextRendering = $true
$Button1.UseVisualStyleBackColor = $true
$Button1.add_Click($Button1_Click