#include "tottymath.h"

void init_LUT(unsigned char LUT[65])
{
	unsigned char i;
	float sin_of,sine;
	for (i=0;i<65;i++)
	{
		sin_of=i*PI/64; // Just need half a sin wave
		sine=sin(sin_of);
		// Use 181.0 as this squared is <32767, so we can multiply two sin or cos without overflowing an int.
		LUT[i]=sine*181.0;
	}
}

int totty_sin(unsigned char LUT[65],int sin_of)
{
	unsigned char inv=0;
	if (sin_of<0)
	{
		sin_of=-sin_of;
		inv=1;
	}
	sin_of&=0x7f; //127
	if (sin_of>64)
	{
		sin_of-=64;
		inv=1-inv;
	}
	if (inv)
		return -LUT[sin_of];
	else
		return LUT[sin_of];
}

int totty_cos(unsigned char LUT[65],int cos_of)
{
	unsigned char inv=0;
	cos_of+=32;// Simply rotate by 90 degrees for COS
	cos_of&=0x7f;//127
	if (cos_of>64)
	{
		cos_of-=64;
		inv=1;
	}
	if (inv)
		return -LUT[cos_of];
	else
		return LUT[cos_of];
}

/*
    Private Sub Form1_Load(sender As Object, e As System.EventArgs) Handles Me.Load
        Dim i As Integer
        For i = 0 To mysize
            LUT(i) = 255 * Math.Sin(i / myscale)
            txt_output.Text &= LUT(i).ToString & vbCrLf
        Next
    End Sub
    Private Function LUTsin(ByVal angle As Double) As Double
        Dim Langle As Integer
        Dim inv As Boolean = False
        Langle = (angle Mod (2 * Math.PI)) * myscale
        If Langle < 0 Then Langle += mysize * 2
        Debug.Print(Langle)
        If Langle >= mysize Then
            inv = True
            Langle -= mysize
        End If
        LUTsin = LUT(Langle) / 255
        If inv Then LUTsin = -LUTsin
    End Function
    Private Function LUTcos(ByVal angle As Double) As Double
        Dim Langle As Integer
        Dim inv As Boolean = False
        Langle = (angle Mod (2 * Math.PI)) * myscale
        Langle -= mysize / 2
        If Langle < 0 Then Langle += mysize * 2
        Debug.Print(Langle)
        If Langle >= mysize Then
            inv = True
            Langle -= mysize
        End If
        LUTcos = LUT(Langle) / 255
        If Not inv Then LUTcos = -LUTcos
    End Function
    Private Sub btn_do_sine_Click(sender As System.Object, e As System.EventArgs) Handles btn_do_sine.Click
        Dim do_angle As Double = 2 * Math.PI * Val(txt_angle.Text) / 360
        Dim ret1 As Double = LUTsin(do_angle)
        Dim ret2 As Double = Math.Sin(do_angle)
        Dim ret3 As Double = LUTcos(do_angle)
        Dim ret4 As Double = Math.Cos(do_angle)
        txt_sine.Text = Format(ret1, "0.00000") & " : " & Format(ret2, "0.00000")
        txt_cosine.Text = Format(ret3, "0.00000") & " : " & Format(ret4, "0.00000")
    End Sub
*/