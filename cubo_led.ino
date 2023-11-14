int columnas[16] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, A5, A4};

int pisos[4] = {A3, A2, A1, A0};

void setup() {
  for(int i = 0; i < 16; i++) {
    pinMode(columnas[i], OUTPUT);
  }

  for(int i = 0; i < 4; i++) {
    pinMode(pisos[i], OUTPUT);
  }

  randomSeed(analogRead(10));
}

void loop() {
  apagarTodo(); // Apaga todos los LEDs
  titilarEncendido(); // Titila todos los LEDs encendidos
  encenderTodo(); // Enciende todos los LEDs
  lluviaAleatoria(); // Animación de lluvia aleatoria
  alrededorBordeAbajo(); // Animación de luces alrededor del borde hacia abajo
  apagarTodo(); // Apaga todos los LEDs
  prenderCentroYAlrededor(); // Alterna entre encender los LEDs del centro y luego los LEDs alrededor en cada cara
  apagarTodo(); // Apaga todos los LEDs
  titilarAleatorio(); // Titila LEDs de manera aleatoria
  rectanguloDiagonal(); // Animación de rectángulo diagonal
  helice(); // Animación de hélice
  apagarTodo(); // Apaga todos los LEDs
  delay(2000); // Espera 2 segundos antes de reiniciar las animaciones
}

/* Animaciones */

void apagarTodo()
{
  for(int i = 0; i < 16; i++)
  {
    digitalWrite(columnas[i], true);
  }
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(pisos[i], false);
  }
}

void encenderTodo()
{
  for(int i = 0; i < 16; i++)
  {
    digitalWrite(columnas[i], false);
  }

  for(int i = 0; i < 4; i++)
  {
    digitalWrite(pisos[i], true);
  }
}

void titilarEncendido()
{
  int i = 150;
  while(i != 0)
  {
    encenderTodo();
    delay(i);
    apagarTodo();
    delay(i);
    i -= 5;
  }
}

void titilarApagado()
{
  encenderTodo();
  for(int i = 0; i != 150; i += 5)
  {
    apagarTodo();
    delay(i + 50);
    encenderTodo();
    delay(i);
  }
}

void alrededorBordeAbajo()
{
  for(int x = 200; x != 0; x -= 50)
  {
    apagarTodo();
    for(int i = 4; i != 0; i--)
    {
      digitalWrite(pisos[i], true);
      digitalWrite(columnas[5], false);
      digitalWrite(columnas[6], false);
      digitalWrite(columnas[9], false);
      digitalWrite(columnas[10], false);
      
      digitalWrite(columnas[0], false);
      delay(x);
      digitalWrite(columnas[0], true);
      digitalWrite(columnas[4], false);
      delay(x);
      digitalWrite(columnas[4], true);
      digitalWrite(columnas[8], false);
      delay(x);
      digitalWrite(columnas[8], true);
      digitalWrite(columnas[12], false);
      delay(x);
      digitalWrite(columnas[12], true);
      digitalWrite(columnas[13], false);
      delay(x);
      digitalWrite(columnas[13], true);
      digitalWrite(columnas[15], false);
      delay(x);
      digitalWrite(columnas[15], true);
      digitalWrite(columnas[14], false);
      delay(x);
      digitalWrite(columnas[14], true);
      digitalWrite(columnas[11], false);
      delay(x);
      digitalWrite(columnas[11], true);
      digitalWrite(columnas[7], false);
      delay(x);
      digitalWrite(columnas[7], true);
      digitalWrite(columnas[3], false);
      delay(x);
      digitalWrite(columnas[3], true);
      digitalWrite(columnas[2], false);
      delay(x);
      digitalWrite(columnas[2], true);
      digitalWrite(columnas[1], false);
      delay(x);
      digitalWrite(columnas[1], true);
    }
  }
}

void titilarAleatorio()
{
  apagarTodo();
  int x = 10;
  for(int i = 0; i != 750; i += 2)
  {
    int pisoAleatorio = random(0, 4);
    int columnaAleatoria = random(0, 16);
    
    digitalWrite(pisos[pisoAleatorio], true);
    digitalWrite(columnas[columnaAleatoria], false);
    delay(x);
    digitalWrite(pisos[pisoAleatorio], false);
    digitalWrite(columnas[columnaAleatoria], true);
    delay(x); 
  }
}

const int numGotas = 3;
int posicionesGotas[numGotas] = {-1, -1, -1};

void lluviaAleatoria()
{
  apagarTodo();
  int x = 100;

  for (int i = 0; i < 60; i += 2)
  {
    moverGotasAbajo();

    for (int j = 0; j < numGotas; j++)
    {
      if (random(10) < 5 && posicionesGotas[j] == -1)
      {
        posicionesGotas[j] = 0;
      }
    }

    actualizarLEDs();

    delay(x + 150);
  }
}

void moverGotasAbajo()
{
  for (int j = 0; j < numGotas; j++)
  {
    if (posicionesGotas[j] != -1)
    {
      posicionesGotas[j]++;

      if (posicionesGotas[j] == 4)
      {
        posicionesGotas[j] = -1;
      }
    }
  }
}

void actualizarLEDs()
{
  apagarTodo();

  for (int j = 0; j < numGotas; j++)
  {
    if (posicionesGotas[j] != -1)
    {
      int columnaAleatoria = random(0, 16);
      digitalWrite(columnas[columnaAleatoria], true);
      digitalWrite(pisos[posicionesGotas[j]], true);
    }
  }
}

void rectanguloDiagonal()
{
  int x = 350;
  apagarTodo();
  for(int count = 0; count < 5; count++)
  {

    for(int i = 0; i < 8; i++)
    {
      digitalWrite(columnas[i], false);
    }
    digitalWrite(pisos[3], true);
    digitalWrite(pisos[2], true);
    delay(x);
    apagarTodo();

    for(int i = 4; i < 12; i++)
    {
      digitalWrite(columnas[i], false);
    }
    digitalWrite(pisos[1], true);
    digitalWrite(pisos[2], true);
    delay(x);
    apagarTodo();

    for(int i = 8; i < 16; i++)
    {
      digitalWrite(columnas[i], false);
    }
    digitalWrite(pisos[0], true);
    digitalWrite(pisos[1], true);
    delay(x);
    apagarTodo();

    for(int i = 4; i < 12; i++)
    {
      digitalWrite(columnas[i], false);
    }
    digitalWrite(pisos[0], true);
    digitalWrite(pisos[1], true);
    delay(x);
    apagarTodo();

    for(int i = 0; i < 8; i++)
    {
      digitalWrite(columnas[i], false);
    }
    digitalWrite(pisos[0], true);
    digitalWrite(pisos[1], true);
    delay(x);
    apagarTodo();

    for(int i = 4; i < 12; i++)
    {
      digitalWrite(columnas[i], false);
    }
    digitalWrite(pisos[1], true);
    digitalWrite(pisos[2], true);
    delay(x);
    apagarTodo();

    for(int i = 8; i < 16; i++)
    {
      digitalWrite(columnas[i], false);
    }
    digitalWrite(pisos[2], true);
    digitalWrite(pisos[3], true);
    delay(x);
    apagarTodo();

    for(int i = 4; i < 12; i++)
    {
      digitalWrite(columnas[i], false);
    }
    digitalWrite(pisos[2], true);
    digitalWrite(pisos[3], true);
    delay(x);
    apagarTodo();
  }

  for(int i = 0; i < 8; i++)
  {
    digitalWrite(columnas[i], false);
  }
  digitalWrite(pisos[3], true);
  digitalWrite(pisos[2], true);
  delay(x);
  apagarTodo();
}

void helice()
{
  apagarTodo();
  int x = 90;
  for(int y = 4; y > 0; y--)
  {
    for(int i = 0; i < 6; i++)
    {
      digitalWrite(pisos[y], true);
   
      apagarColumnas();
      digitalWrite(columnas[0], false);
      digitalWrite(columnas[5], false);
      digitalWrite(columnas[10], false);
      digitalWrite(columnas[15], false);
      delay(x);
   
      apagarColumnas();
      digitalWrite(columnas[4], false);
      digitalWrite(columnas[5], false);
      digitalWrite(columnas[10], false);
      digitalWrite(columnas[11], false);
      delay(x);
      
      apagarColumnas();
      digitalWrite(columnas[6], false);
      digitalWrite(columnas[7], false);
      digitalWrite(columnas[8], false);
      digitalWrite(columnas[9], false);
      delay(x);
    
      apagarColumnas();
      digitalWrite(columnas[3], false);
      digitalWrite(columnas[6], false);
      digitalWrite(columnas[9], false);
      digitalWrite(columnas[12], false);
      delay(x);
      
      apagarColumnas();
      digitalWrite(columnas[2], false);
      digitalWrite(columnas[6], false);
      digitalWrite(columnas[9], false);
      digitalWrite(columnas[13], false);
      delay(x);
     
      apagarColumnas();
      digitalWrite(columnas[1], false);
      digitalWrite(columnas[5], false);
      digitalWrite(columnas[10], false);
      digitalWrite(columnas[14], false);
      delay(x);
    }
  }

  apagarColumnas();
  digitalWrite(columnas[0], false);
  digitalWrite(columnas[5], false);
  digitalWrite(columnas[10], false);
  digitalWrite(columnas[15], false);
  delay(x);
}

void prenderCentroYAlrededor() {
  int centro[4] = {5, 6, 9, 10};

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(columnas[centro[j]], false);
    }
    delay(500); 

    for (int j = 0; j < 16; j++) {
      bool esCentro = false;
      for (int k = 0; k < 4; k++) {
        if (centro[k] == j) {
          esCentro = true;
          break;
        }
      }
      if (!esCentro) {
        digitalWrite(columnas[j], false);
      } else {
        digitalWrite(columnas[j], true);
      }
    }
    delay(500);
    apagarTodo();
  }
}

void apagarColumnas()
{
  for(int i = 0; i < 16; i++)
  {
    digitalWrite(columnas[i], true);
  }
}