package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

import javax.swing.*;
import java.util.ResourceBundle;

public class Controller {
    Float data = 0f;
    int operation = -1;
    @FXML
    private ResourceBundle resources;
    @FXML
    private Button two;

    @FXML
    private Button three;

    @FXML
    private Button add;

    @FXML
    private Button four;

    @FXML
    private Button mul;

    @FXML
    private Button equal;

    @FXML
    private Button zero;

    @FXML
    private Button CE;

    @FXML
    private Button divide;

    @FXML
    private Button nine;

    @FXML
    private Button eight;

    @FXML
    private Button seven;

    @FXML
    private Button sub;

    @FXML
    private Button six;

    @FXML
    private Button five;

    @FXML
    private Button one;

    @FXML
    private TextField inpout;

    @FXML
    public void actionhandler(ActionEvent actionEvent){
        if(actionEvent.getSource() == one){
            inpout.setText(inpout.getText()+"1");
        }else if(actionEvent.getSource() == two){
            inpout.setText(inpout.getText()+"2");
        }else if(actionEvent.getSource() == three){
            inpout.setText(inpout.getText()+"3");
        }else if(actionEvent.getSource() == four){
            inpout.setText(inpout.getText()+"4");
        }else if(actionEvent.getSource() == five){
            inpout.setText(inpout.getText()+"5");
        }else if(actionEvent.getSource() == six){
            inpout.setText(inpout.getText()+"6");
        }else if(actionEvent.getSource() == seven){
            inpout.setText(inpout.getText()+"7");
        }else if(actionEvent.getSource() == eight){
            inpout.setText(inpout.getText()+"8");
        }else if(actionEvent.getSource() == nine){
            inpout.setText(inpout.getText()+"9");
        }else if(actionEvent.getSource() == zero){
            inpout.setText(inpout.getText()+"0");
        }else if(actionEvent.getSource() == CE){
            inpout.setText("");
        }else if(actionEvent.getSource() == add){
            operation=1;
            if(data!=0) {
                Float aa = data +Float.parseFloat(inpout.getText());
                data = aa;
            }else
            data = Float.parseFloat(inpout.getText());
            inpout.setText("");
        }else if(actionEvent.getSource() == sub){
            operation=2;
            if(data!=0) {
                Float aa = data -Float.parseFloat(inpout.getText());
                data = aa;
            }else
            data = Float.parseFloat(inpout.getText());
            inpout.setText("");
        }else if(actionEvent.getSource() == mul){
            operation=3;
            if(data!=0) {
                Float aa = data *Float.parseFloat(inpout.getText());
                data = aa;
            }else
            data = Float.parseFloat(inpout.getText());
            inpout.setText("");
        }else if(actionEvent.getSource() == divide){
            operation=4;
            if(data!=0&&Float.parseFloat(inpout.getText())!=0)
            {   Float aa = data /Float.parseFloat(inpout.getText());
                    data = aa;
                }else
            data = Float.parseFloat(inpout.getText());
            inpout.setText("");
        }else if(actionEvent.getSource()==equal){
            Float second=Float.parseFloat(inpout.getText());
            switch (operation){
                case 1:
                    Float ans=data+second;
                    inpout.setText(String.valueOf(ans));
                    data = 0f;
                    break;
                case 2:
                    ans=data-second;
                    inpout.setText(String.valueOf(ans));
                    data = 0f;
                    break;
                case 3:
                    ans=data*second;
                    inpout.setText(String.valueOf(ans));
                    data = 0f;
                    break;
                case 4:
                    if(second==0) {
                        inpout.setText("ERROR");
                        data = 0f;
                            }
                    else
                    {ans=data/second;
                        inpout.setText(String.valueOf(ans));
                        data = 0f;}
            }
        }

    }
}
