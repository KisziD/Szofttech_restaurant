import java.io.*;

class TimetableGenerator{

    public static void main(String args[]){
        try {
            FileWriter fw=new FileWriter(new File("timetable.txt"));

            int time=1605520800;
            int count=0;
            while(time<1637056801){
                if(count<7){
                    fw.write(time+"!false;false;false;false;false;false\n");
                    time+=7200;
                    count++;
                }else if(count==7){
                    count=0;
                    time+=36000;
                }
            }
            fw.close();

        } catch (Exception e) {
            
        }
    }


}