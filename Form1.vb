Imports Excel = Microsoft.Office.Interop.Excel

Public Class Form1

    Dim APP As New Excel.Application
    Dim worksheet As Excel.Worksheet
    Dim workbook As Excel.Workbook
    Dim Player As String
    'Dim Email As String
    Dim available1 As String
    Dim unavailable1 As String
    'Dim PlayerStartTime As Integer
    'Dim PlayerEndTime As Integer

    Public Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) _
        Handles MyBase.Load
        workbook = APP.Workbooks.Open("C:\Users\Ronald\Desktop\IntroToProgramming\OTB\OTB\Roster.xlsx")
        worksheet = workbook.Worksheets("sheet1")
        MsgBox("Welcome to Off the Bat!")
    End Sub

    Sub count()
        available1 = RichTextBox1.Lines.Count - 1
        unavailable1 = RichTextBox2.Lines.Count - 1
        Label7.Text = ("Avaliable:  " + available1)
        Label8.Text = ("Unavailable: " + unavailable1)
    End Sub

    Sub excelParser()
        Dim StartTime As Integer
        Dim EndTime As Integer
        Dim x As Integer = 2 'starts at name
        Dim y As Integer = 1 'starts at name
        Dim Day As String

        For i = 0 To 25
            Player = worksheet.Cells(x, y).Text
            If Player = Player Then
                Day = worksheet.Cells(x, y + 1).Text
                If Day = ComboBox1.SelectedItem Then
                    StartTime = worksheet.Cells(x, y + 2).Value
                    TextBox2.AppendText(StartTime)
                    EndTime = worksheet.Cells(x, y + 3).Value
                    TextBox4.AppendText(EndTime)
                    'Email = worksheet.Cells(x, y + 4).Text
                    availability()
                    clear()
                Else
                    clear()
                End If
                x = x + 1
            End If
        Next
        count()
        ' Missing()
    End Sub

    Public Property Workbooks As Object

    Sub checkError()
        If TextBox1.Text > TextBox3.Text Or TextBox1.Text = TextBox3.Text Then
            MsgBox("Error!!!!!!!!! Coaches start time for practice must be before coaches end time for practice")
        ElseIf TextBox2.Text > TextBox4.Text Or TextBox2.Text = TextBox4.Text Then
            MsgBox("Error!!!!!!!!! Player start time for class must be before player end time for class")
        Else
            MsgBox("Valid Entries")
        End If
    End Sub

    Sub availability()
        If TextBox1.Text = TextBox2.Text And TextBox3.Text = TextBox4.Text Then
            unavailable()
        ElseIf TextBox1.Text = TextBox2.Text Or TextBox3.Text = TextBox4.Text Then
            unavailable()
        ElseIf TextBox1.Text < TextBox2.Text And TextBox3.Text > TextBox4.Text Then
            unavailable()
        ElseIf TextBox1.Text > TextBox2.Text And TextBox3.Text < TextBox4.Text Then
            unavailable()
        ElseIf TextBox2.Text < TextBox1.Text And TextBox4.Text < TextBox3.Text And TextBox4.Text > TextBox1.Text Then
            unavailable()
        ElseIf TextBox2.Text > TextBox1.Text And TextBox4.Text > TextBox3.Text And TextBox2.Text < TextBox3.Text Then
            unavailable()
        ElseIf TextBox2.Text < TextBox1.Text And TextBox4.Text < TextBox3.Text And TextBox4.Text > TextBox1.Text Then
            unavailable()
        Else
            available()
            RichTextBox3.Text = ("Message: " + vbNewLine + "Practice will be on " + ComboBox1.SelectedItem + " from " + TextBox1.Text + " to " + TextBox3.Text + "." + vbNewLine)
            'RichTextBox3.AppendText(Email + "; ")
        End If
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        checkError()
        excelParser()
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        'clear textboxs'
        TextBox1.Text = ("")
        TextBox2.Text = ("")
        TextBox3.Text = ("")
        TextBox4.Text = ("")
        RichTextBox3.Text = ("")
    End Sub

    Sub clear()
        TextBox2.Text = ("")
        TextBox4.Text = ("")
    End Sub

    Sub unavailable()
        RichTextBox2.AppendText(Player + vbNewLine)
    End Sub

    Sub available()
        RichTextBox1.AppendText(Player + vbNewLine)
    End Sub

    Sub Missing()
        If NumericUpDown1.Text < unavailable1 Then
            MsgBox("More than " + NumericUpDown1.Value + " will be missing. You should look at a different time slot for practice.")
        Else
            MsgBox("This is a valid time for practice but " + NumericUpDown1.Value + " will be missing.")
        End If
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        OpenFileDialog1.Title = "Please Select a File"
        OpenFileDialog1.InitialDirectory = "C:temp"
        OpenFileDialog1.ShowDialog()
    End Sub

    Private Sub OpenFileDialog1_FileOk(sender As Object, e As System.ComponentModel.CancelEventArgs) Handles OpenFileDialog1.FileOk
        Dim strm As System.IO.Stream
        Dim Roster As String

        strm = OpenFileDialog1.OpenFile()

        Roster = OpenFileDialog1.FileName.ToString()

        If Not (strm Is Nothing) Then

            'insert code to read the file data
            workbook = APP.Workbooks.Open(Roster)
            worksheet = workbook.Worksheets("sheet1")
            MsgBox("Welcome to Off the Bat!")

            strm.Close()

            MessageBox.Show("file closed")

        End If
    End Sub
End Class
