package view;

import java.net.URL;
import java.text.DecimalFormatSymbols;
import java.text.NumberFormat;
import java.text.ParseException;
import java.util.Locale;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Platform;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class PrincipalController implements Initializable {

    private final DecimalFormatSymbols ds = new DecimalFormatSymbols(Locale.getDefault());
    private final NumberFormat nf = NumberFormat.getInstance​(Locale.getDefault());

    @FXML
    private TextField txtFldValor1;

    @FXML
    private TextField txtFldValor2;

    @FXML
    private Button btnSomar;

    @FXML
    private Button btnSubtrair;

    @FXML
    private Button btnMultiplicar;

    @FXML
    private Button btnDividir;

    @FXML
    private Button btnLimpar;

    @FXML
    private Button btnSair;

    @FXML
    private Label lblResultado;

    @FXML
    private void btnSairClick(ActionEvent event) {
        System.exit(0);
    }

    @FXML
    private void btnLimparClick(ActionEvent event) {
        txtFldValor1.clear();
        txtFldValor2.clear();
        lblResultado.setText("Resultado");

        //Dar o foco em Valor1
        Platform.runLater(() -> {
            txtFldValor1.requestFocus();
        });
    }

    @FXML
    private void btnSomarClick(ActionEvent event) {
        try {
            double valor1 = nf.parse(txtFldValor1.getText()).doubleValue();
            double valor2 = nf.parse(txtFldValor2.getText()).doubleValue();
            lblResultado.setText("A soma vale: " + nf.format(valor1 + valor2));
        } catch (ParseException ex) {
            Logger.getLogger(PrincipalController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @FXML
    private void btnSubtrairClick(ActionEvent event) {
        try {
            double valor1 = nf.parse(txtFldValor1.getText()).doubleValue();
            double valor2 = nf.parse(txtFldValor2.getText()).doubleValue();
            lblResultado.setText("A subtração vale: " + nf.format(valor1 - valor2));
        } catch (ParseException ex) {
            Logger.getLogger(PrincipalController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @FXML
    private void btnMultiplicarClick(ActionEvent event) {
        try {
            double valor1 = nf.parse(txtFldValor1.getText()).doubleValue();
            double valor2 = nf.parse(txtFldValor2.getText()).doubleValue();
            lblResultado.setText("A multiplicação vale: " + nf.format(valor1 * valor2));
        } catch (ParseException ex) {
            Logger.getLogger(PrincipalController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @FXML
    private void btnDividirClick(ActionEvent event) {
        try {
            double valor1 = nf.parse(txtFldValor1.getText()).doubleValue();
            double valor2 = nf.parse(txtFldValor2.getText()).doubleValue();
            lblResultado.setText("A divisão vale: " + nf.format(valor1 / valor2));
        } catch (ParseException ex) {
            Logger.getLogger(PrincipalController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @Override

    public void initialize(URL url, ResourceBundle rb) {

        txtFldValor1.textProperty().addListener((ObservableValue<? extends String> observable, String oldValue, String newValue) -> {
            if (!newValue.matches("\\d*")) {
                txtFldValor1.setText(newValue.replaceAll("[^\\d]", ""));
            }
        });

        txtFldValor2.textProperty().addListener((ObservableValue<? extends String> observable, String oldValue, String newValue) -> {
            if (!newValue.matches("\\d*")) {
                txtFldValor2.setText(newValue.replaceAll("[^\\d]", ""));
            }
        });
    }
}
