package view;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;

public class PrincipalController implements Initializable {

    @FXML
    private RadioButton rdbtnCelsius;

    @FXML
    private RadioButton rdbtnFarenheit;

    @FXML
    private TextField txtfldTemperatura;

    @FXML
    private Label lblResultado;

    @FXML
    private Button btnLimpar;

    @FXML
    private Button btnCalcular;

    @FXML
    private Button btnSair;

    @FXML
    private void btnSairClick(ActionEvent event) {
        System.exit(0);
    }

    @FXML
    private void btnCalcularClick(ActionEvent event) {
        if (!(txtfldTemperatura.getText().isEmpty())) {
            char origem;
            String destino;
            if (rdbtnCelsius.isSelected()) {
                origem = 'C';
                destino = " °F";
            } else {
                origem = 'F';
                destino = " °C";
            }
        }
    }

    private double ConverteTemperatura(double temperatura, char origem) {
        switch (origem) {
            case 'C': {
                return (temperatura * 1.8) + 32;
            }
            case 'F': {
                return (temperatura - 32) / 1.8;
            }
        }
        return 0;
    }

    @FXML
    private void btnLimparClick(ActionEvent event) {
        txtfldTemperatura.clear();
        rdbtnCelsius.setSelected(true);
        lblResultado.setVisible(false);
        Platform.runLater(() -> {
            txtfldTemperatura.requestFocus();
        });
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {

        Platform.runLater(() -> {
            txtfldTemperatura.requestFocus();
        });
    }
}
