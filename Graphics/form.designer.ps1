$Form1 = New-Object -TypeName System.Windows.Forms.Form
[System.Windows.Forms.Button]$Button1 = $null
[System.Windows.Forms.OpenFileDialog]$OpenFileDialog1 = $null
[System.Windows.Forms.Label]$Label1 = $null
[System.Windows.Forms.Label]$Label2 = $null
[System.Windows.Forms.Label]$Label3 = $null
[System.Windows.Forms.Label]$Label4 = $null
function InitializeComponent
{
$Button1 = (New-Object -TypeName System.Windows.Forms.Button)
$OpenFileDialog1 = (New-Object -TypeName System.Windows.Forms.OpenFileDialog)
$Label1 = (New-Object -TypeName System.Windows.Forms.Label)
$Label2 = (New-Object -TypeName System.Windows.Forms.Label)
$Label3 = (New-Object -TypeName System.Windows.Forms.Label)
$Label4 = (New-Object -TypeName System.Windows.Forms.Label)
$Form1.SuspendLayout()
#
#Button1
#
$Button1.Location = (New-Object -TypeName System.Drawing.Point -ArgumentList @([System.Int32]42,[System.Int32]146))
$Button1.Name = [System.String]'Button1'
$Button1.Size = (New-Object -TypeName System.Drawing.Size -ArgumentList @([System.Int32]301,[System.Int32]103))
$Button1.TabIndex = [System.Int32]0
$Button1.Text = [System.String]'Open to choose file'
$Button1.UseCompatibleTextRendering = $true
$Button1.UseVisualStyleBackColor = $true
$Button1.add_Click($Button1_Click)
#
#OpenFileDialog1
#
$OpenFileDialog1.FileName = [System.String]'OpenFileDialog1'
$OpenFileDialog1.add_FileOk($OpenFileDialog1_FileOk)
#
#Label1
#
$Label1.Location = (New-Object -TypeName System.Drawing.Point -ArgumentList @([System.Int32]619,[System.Int32]96))
$Label1.Name = [System.String]'Label1'
$Label1.Size = (New-Object -TypeName System.Drawing.Size -ArgumentList @([System.Int32]166,[System.Int32]65))
$Label1.TabIndex = [System.Int32]1
$Label1.UseCompatibleTextRendering = $true
#
#Label2
#
$Label2.Font = (New-Object -TypeName System.Drawing.Font -ArgumentList @([System.String]'Tahoma',[System.Single]18,[System.Drawing.FontStyle]::Regular,[System.Drawing.GraphicsUnit]::Point,([System.Byte][System.Byte]0)))
$Label2.Location = (New-Object -TypeName System.Drawing.Point -ArgumentList @([System.Int32]422,[System.Int32]229))
$Label2.Name = [System.String]'Label2'
$Label2.Size = (New-Object -TypeName System.Drawing.Size -ArgumentList @([System.Int32]460,[System.Int32]53))
$Label2.TabIndex = [System.Int32]2
$Label2.Text = [System.String]'Original file size: 158 bytes'
$Label2.UseCompatibleTextRendering = $true
#
#Label3
#
$Label3.Font = (New-Object -TypeName System.Drawing.Font -ArgumentList @([System.String]'Tahoma',[System.Single]18,[System.Drawing.FontStyle]::Regular,[System.Drawing.GraphicsUnit]::Point,([System.Byte][System.Byte]0)))
$Label3.Location = (New-Object -TypeName System.Drawing.Point -ArgumentList @([System.Int32]422,[System.Int32]282))
$Label3.Name = [System.String]'Label3'
$Label3.Size = (New-Object -TypeName System.Drawing.Size -ArgumentList @([System.Int32]533,[System.Int32]75))
$Label3.TabIndex = [System.Int32]3
$Label3.Text = [System.String]'Compressed file size: 112 bytes'
$Label3.UseCompatibleTextRendering = $true
#
#Label4
#
$Label4.Font = (New-Object -TypeName System.Drawing.Font -ArgumentList @([System.String]'Tahoma',[System.Single]18,[System.Drawing.FontStyle]::Regular,[System.Drawing.GraphicsUnit]::Point,([System.Byte][System.Byte]0)))
$Label4.Location = (New-Object -TypeName System.Drawing.Point -ArgumentList @([System.Int32]422,[System.Int32]336))
$Label4.Name = [System.String]'Label4'
$Label4.Size = (New-Object -TypeName System.Drawing.Size -ArgumentList @([System.Int32]461,[System.Int32]59))
$Label4.TabIndex = [System.Int32]4
$Label4.Text = [System.String]'Compression rate: 29.11%'
$Label4.UseCompatibleTextRendering = $true
#
#Form1
#
$Form1.ClientSize = (New-Object -TypeName System.Drawing.Size -ArgumentList @([System.Int32]904,[System.Int32]474))
$Form1.Controls.Add($Label4)
$Form1.Controls.Add($Label3)
$Form1.Controls.Add($Label2)
$Form1.Controls.Add($Label1)
$Form1.Controls.Add($Button1)
$Form1.Text = [System.String]'Text-Compressor'
$Form1.add_Load($Form1_Load)
$Form1.ResumeLayout($false)
Add-Member -InputObject $Form1 -Name base -Value $base -MemberType NoteProperty
Add-Member -InputObject $Form1 -Name Button1 -Value $Button1 -MemberType NoteProperty
Add-Member -InputObject $Form1 -Name OpenFileDialog1 -Value $OpenFileDialog1 -MemberType NoteProperty
Add-Member -InputObject $Form1 -Name Label1 -Value $Label1 -MemberType NoteProperty
Add-Member -InputObject $Form1 -Name Label2 -Value $Label2 -MemberType NoteProperty
Add-Member -InputObject $Form1 -Name Label3 -Value $Label3 -MemberType NoteProperty
Add-Member -InputObject $Form1 -Name Label4 -Value $Label4 -MemberType NoteProperty
}
. InitializeComponent
