import java.io.*;
import java.util.Scanner;

public class WriteByLine {
    public static void writeByLine(String path,int line){
        try{
            String temp = "";
            String newStr;
            Scanner sc = new Scanner(System.in);
            File file = new File(path);
            FileInputStream fis = new FileInputStream(file);
            InputStreamReader isr = new InputStreamReader(fis);
            BufferedReader br = new BufferedReader(isr);
            StringBuffer buf = new StringBuffer();

            System.out.print("请输入要插入的内容：");
            newStr = sc.nextLine();
            //保存该行前面的内容
            for(int j = 1;(temp = br.readLine())!=null;j++){
                if(j==line){
                    buf = buf.append(newStr+"\r\n");
                    buf = buf.append(temp+"\r\n");
                }else{
                    buf = buf.append(temp+"\r\n");
                }
            }
            br.close();

            FileOutputStream fos = new FileOutputStream(file);
            OutputStreamWriter osw = new OutputStreamWriter(fos);
            BufferedWriter bw = new BufferedWriter(osw);
            bw.write(String.valueOf(buf));
            bw.flush();
            bw.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    //文件内容的总行数
    public static int getTotalLine(String path){
        FileReader in = null;
        LineNumberReader reader = null;
        String s = null;
        int lines = 0;
        try{
            in = new FileReader(path);
            reader = new LineNumberReader(in);
            s = reader.readLine();

            while(s != null){
                lines++;
                s = reader.readLine();
            }
        }catch (IOException e){
            e.printStackTrace();
        }finally {
            if(reader!=null||in!=null){
                try{
                    reader.close();
                    in.close();
                }catch(IOException e){
                    e.printStackTrace();
                }
            }
        }
        return lines;
    }

    public static void main(String[] args) {
        String path;
        int line;

        Scanner sc = new Scanner(System.in);
        System.out.print("请输入路径及文件名：");
        path = sc.nextLine();
        while(true){
            System.out.println("请输入要插入的行数：");
            System.out.println("如果要退出请输入0");
            line = sc.nextInt();
            if(line <= 0 ||line>getTotalLine(path)){
                System.out.println("不在文件行数范围内");
                break;
            }
            writeByLine(path,line);
        }

    }
}
