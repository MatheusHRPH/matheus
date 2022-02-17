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
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;

public class PrincipalController implements Initializable {

    private final char ds = new DecimalFormatSymbols(Locale.getDefault(Locale.Category.FORMAT)).getDecimalSeparator();
    
    private final NumberFormat nf = NumberFormat.getInstance(Locale.getDefault());

    @FXML
    private RadioButton rdBtnFeminino;

    @FXML
    private RadioButton rdBtnMasculino;

    @FXML
    private TextField txtFldPeso;

    @FXML
    private TextField txtFldAltura;

    @FXML
    private Button btnCalcular;

    @FXML
    private Button btnLimpar;

    @FXML
    private Label lblImc;

    @FXML
    private Label lblCondicao;

    @FXML
    private void btnLimparClick(ActionEvent event) {
        txtFldPeso.clear();
        txtFldAltura.clear();
        lblImc.setText("IMC: ");
        lblCondicao.setText("Condição: ");

        Platform.runLater(() -> {
            txtFldPeso.requestFocus();
        });
    }

    @FXML
    private void btnCalcularClick(ActionEvent event) throws ParseException {
        try {
            double peso = nf.parse(txtFldPeso.getText()).doubleValue();
            double altura = nf.parse(txtFldAltura.getText()).doubleValue();
            lblImc.setText("IMC: " + nf.format(peso / (altura * altura)));
            if ((!(txtFldPeso.getText().isEmpty())) && (!(txtFldAltura.getText().isEmpty()))) {
                if (rdBtnFeminino.isSelected()) {
                    System.out.println("Fem");
                } else {
                    System.out.println("Mas");
                }
            }

        } catch (ParseException ex) {
            Logger.getLogger(PrincipalController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {

        Platform.runLater(() -> {
            txtFldPeso.requestFocus();
        });
        
        txtFldPeso.textProperty().addListener{
            (observable, oldValue, newValue) -> {
                if (!newValue.matches("(\\-)?\\d*(\\" + ds + "\\d*)?") && !newValue.isEmpty()) {
                    txtFldPeso.setText(oldValue);
                }
            });
    }
        
    }

