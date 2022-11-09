#define ledVermelhoA 6
#define ledVerdeA 7
#define ledVerdeB 8
#define ledVermelhoB 9
#define triggerg 10
#define echog 11
#define triggerr 12
#define echor 13
float tVaga1 = 0, dVaga1 = 0;
float tVaga2 = 0, dVaga2 = 0;
int vagasLivres = 2;
int vagasOcupadas = 0;

// inclui a biblioteca de utilização do display de LCD:
#include <LiquidCrystal.h>
// Caracteríscias iniciais do hardware
LiquidCrystal lcd(0, 1, 2, 3, 4, 5);
// Sequência p/comunicação com 6 pinos (RS-EN-D4-D5-D6-D7)
// Sequência p/comunicação com 10 pinos(RS-EN-D1-D2-D3-D4-D5-D6-D7)
void setup()
{

    lcd.begin(16, 2);

    pinMode(ledVerdeA, OUTPUT);
    pinMode(ledVermelhoB, OUTPUT);
    pinMode(ledVermelhoA, OUTPUT);
    pinMode(ledVerdeB, OUTPUT);
    pinMode(triggerg, OUTPUT);
    pinMode(triggerr, OUTPUT);
    pinMode(echog, INPUT);
    pinMode(echor, INPUT);
}
void loop()
{
    digitalWrite(triggerr, LOW);
    delayMicroseconds(5);
    digitalWrite(triggerr, HIGH);
    delayMicroseconds(5);
    digitalWrite(triggerr, LOW);
    float tVaga1 = pulseIn(echor, HIGH);
    dVaga1=(tVaga1*340/20000)/100;
    delayMicroseconds(5);


    digitalWrite(triggerg, LOW);
    delayMicroseconds(5);
    digitalWrite(triggerg, HIGH);
    delayMicroseconds(5);
    digitalWrite(triggerg, LOW);
    float tVaga2 = pulseIn(echog, HIGH);
    dVaga2 = (tVaga2*340/20000)/100;
    delay(90);

    if (dVaga1 < 2.00 && dVaga2 < 2.00)
    {
        todasVagasOcupadas();
    }

    else if (dVaga1 < 2.00 && dVaga2 > 2.00)
    {
        vagaAOcupada();
    }

    else if (dVaga1 > 2.00 && dVaga2 < 2.00)
    {
        vagaBOcupada();
    }

    else if (dVaga1 > 2.00 && dVaga2 > 2.00)
    {
        todasVagasLivres();
    }
}

void todasVagasOcupadas()
{
    digitalWrite(ledVerdeA, LOW);
    digitalWrite(ledVerdeB, LOW);
    digitalWrite(ledVermelhoA, HIGH);
    digitalWrite(ledVermelhoB, HIGH);

    vagasLivres = 0;
    vagasOcupadas = 2;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vagas livres   " + String(vagasLivres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas " + String(vagasOcupadas));
}

void vagaAOcupada()
{
    digitalWrite(ledVerdeA, HIGH);
    digitalWrite(ledVerdeB, LOW);
    digitalWrite(ledVermelhoA, LOW);
    digitalWrite(ledVermelhoB, HIGH);

    vagasLivres = 1;
    vagasOcupadas = 1;

    lcd.clear();
    lcd.setCursor(0, 0);

    lcd.print("Vagas livres   " + String(vagasLivres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas " + String(vagasOcupadas));
}

void vagaBOcupada()
{
    digitalWrite(ledVerdeA, LOW);
    digitalWrite(ledVerdeB, HIGH);
    digitalWrite(ledVermelhoA, HIGH);
    digitalWrite(ledVermelhoB, LOW);

    vagasLivres = 1;
    vagasOcupadas = 1;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vagas livres   " + String(vagasLivres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas " + String(vagasOcupadas));
}

void todasVagasLivres()
{
    digitalWrite(ledVerdeA, HIGH);
    digitalWrite(ledVerdeB, HIGH);
    digitalWrite(ledVermelhoA, LOW);
    digitalWrite(ledVermelhoB, LOW);

    vagasLivres = 2;
    vagasOcupadas = 0;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vagas livres   " + String(vagasLivres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas " + String(vagasOcupadas));
}
