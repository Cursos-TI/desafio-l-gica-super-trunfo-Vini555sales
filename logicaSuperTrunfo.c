#include <stdio.h>
#include <string.h>

typedef enum {Population, Area, PIB, TouristPoints, PIBperCapita, PopulationDensity, SuperPower}ComparationType;

struct Card
{
    char cardName[12];
    char stateName;
    char cityCode[12];

    char cityName[50];
    unsigned int population;
    float area;
    float pib;
    int touristPoints;

    float pibPerCapita;
    float populationDensity;

    float superPower;
};

void LineBreak(int lines)
{
    if(lines <= 0) return;

    for(int i = 0; i < lines; i++)
    {
        printf("\n");
    }
}

float DivideNumbers(float a, float b)
{
    float result = a / b;

    return result;
}

float CalculateSuperPower(float population, float area, float pib, float touristPoint, float pibPerCapita, float populationDensity)
{
    float result = population + area + pib + touristPoint + pibPerCapita - populationDensity;

    return result;
}

void ShowCardAttributes(struct Card card)
{
    printf("%s", card.cardName);
    LineBreak(1);
    printf("O Estado é: %c", card.stateName);
    LineBreak(1);
    printf("O Código é: %s", card.cityCode);
    LineBreak(1);
    printf("O nome da cidade é: %s", card.cityName);
    LineBreak(1);
    printf("A população da cidade é: %d", card.population);
    LineBreak(1);
    printf("A área da cidade é : %.2f", card.area);
    LineBreak(1);
    printf("O PIB da cidade é: %.2f", card.pib);
    LineBreak(1);
    printf("A quantidade de pontos turísticos é: %d", card.touristPoints);
    LineBreak(1);
    printf("O PIB per Capita da cidade é: %.2f", card.pibPerCapita);
    LineBreak(1);
    printf("A densidade da cidade é: %.2f", card.populationDensity);
}

struct Card FillCardAttributes(char cardName[], struct Card card)
{
    strcpy(card.cardName, cardName);
    printf("%s\n", &card.cardName);

    printf("Digite a primeira letra do seu estado: ");
    scanf(" %c", &card.stateName);

    printf("Digite um número de 01 à 04: ");
    scanf("%s", &card.cityCode);

    printf("Digite o primeiro nome da sua cidade: ");
    scanf("%s", &card.cityName);

    printf("Digite o número de habitantes da sua cidade: ");
    scanf("%d", &card.population);

    printf("Digite a área da sua cidade: ");
    scanf("%f", &card.area);

    printf("Digite o PIB da sua cidade: ");
    scanf("%f", &card.pib);

    printf("Digite a quantidade de pontos túristicos existentes na sua cidade: ");
    scanf("%d", &card.touristPoints);

    card.populationDensity = DivideNumbers(card.population, card.area);
    card.pibPerCapita = DivideNumbers(card.pib, card.population);
    card.superPower = card.population + card.area + card.pib + card.touristPoints + card.pibPerCapita - card.populationDensity;

    return card;
}

void ShowCompareOptions()
{
    printf("Quais atributos você deseja comparar?");
    LineBreak(1);

    printf("1 = Population");
    LineBreak(1);

    printf("2 = Área");
    LineBreak(1);

    printf("3 = PIB");
    LineBreak(1);

    printf("4 = Pontos turísticos");
    LineBreak(1);

    printf("5 = PIB per Capita");
    LineBreak(1);

    printf("6 = Densidade demográfica");
    LineBreak(1);

    printf("7 = Super Poder");
    LineBreak(2);

   
}

void CompareCards(int selectedOptionArray[], struct Card card1, struct Card card2)
{
    int card1Score = 0;
    int card2Score = 0;

    printf("RESULTADO");
    LineBreak(2);

    for(int i = 0; i < 2; i++)
    {
        int currentOption = selectedOptionArray[i];

        switch(currentOption)
        {
            case Population + 1:

                if(card1.population != card2.population)
                {
                    printf("População: %s venceu", card1.population > card2.population ? card1.cardName : card2.cardName);

                    card1Score += card1.population > card2.population ? 1 : 0;
                    card2Score += card1.population < card2.population ? 1 : 0;

                    break;
                }

                card1Score++;
                card2Score++;

                printf("População: Empatou");

            break;

            case Area + 1:

                if(card1.area != card2.area)
                {
                    printf("Área: %s venceu", card1.area > card2.area ? card1.cardName : card2.cardName);

                    card1Score += card1.area > card2.area ? 1 : 0;
                    card2Score += card1.area < card2.area ? 1 : 0;

                    break;
                }

                card1Score++;
                card2Score++;

                printf("Area: Empatou");
                
            break;

            case PIB + 1:

                if(card1.pib != card2.pib)
                {
                    printf("PIB: %s venceu", card1.pib > card2.pib ? card1.cardName : card2.cardName);

                    card1Score += card1.pib > card2.pib ? 1 : 0;
                    card2Score += card1.pib < card2.pib ? 1 : 0;

                    break;
                }

                card1Score++;
                card2Score++;

                printf("PIB: Empatou");

            break;

            case TouristPoints + 1:

                if(card1.touristPoints != card2.touristPoints)
                {
                    printf("Quantidade de pontos Turísticos: %s venceu", card1.touristPoints > card2.touristPoints ? card1.cardName : card2.cardName);

                    card1Score += card1.touristPoints > card2.touristPoints ? 1 : 0;
                    card2Score += card1.touristPoints < card2.touristPoints ? 1 : 0;
                    break;
                }

                card1Score++;
                card2Score++;

                printf("Quantidade de pontos Turísticos: Empatou");
            break;

            case PIBperCapita + 1:
                if(card1.pibPerCapita != card2.pibPerCapita)
                {
                    printf("PIB per Capita: %s venceu", card1.pibPerCapita > card2.pibPerCapita ? card1.cardName : card2.cardName);
                    
                    card1Score += card1.pibPerCapita > card2.pibPerCapita ? 1 : 0;
                    card2Score += card1.pibPerCapita < card2.pibPerCapita ? 1 : 0;

                    break;
                }

                printf("PIB per Capita: Empatou");
            break;

            case PopulationDensity + 1:

                if(card1.populationDensity != card2.populationDensity)
                {
                    printf("Densidade Demográfica: %s venceu", card1.populationDensity < card2.populationDensity ? card1.cardName : card2.cardName);
                    card1Score += card1.populationDensity > card2.populationDensity ? 1 : 0;
                    card2Score += card1.populationDensity < card2.populationDensity ? 1 : 0;

                    break;
                }

                card1Score++;
                card2Score++;

                printf("Densidade Demográfica: Empatou");
            break;

            case SuperPower + 1:

                if(card1.superPower != card2.superPower)
                {
                    printf("Super Poder: %s venceu", card1.superPower > card2.superPower ? card1.cardName : card2.cardName);

                    card1Score += card1.superPower > card2.superPower ? 1 : 0;
                    card2Score += card1.superPower < card2.superPower ? 1 : 0;

                    break;
                }

                card1Score++;
                card2Score++;

                printf("Super Poder: Empatou");
            break;
        }
        
        LineBreak(i == 1 ? 2 : 1);
    }

   

    if(card1Score == card2Score)
    {
        printf("As cartas Empataram");
        return;
    }

    printf("A carta Vencedora foi: %s", card1Score > card2Score ? card1.cardName : card2.cardName);

}

void Welcome()
{
    printf("Bem vindo ao Jogo SUPER TRUNFO!");
}

int main() 
{
    Welcome();
    LineBreak(2);

    //Definição das cartas
    struct Card card1;
    struct Card card2;

    //Preenchimento dos atributos
    card1 = FillCardAttributes("Carta 1", card1);
    LineBreak(1);
    card2 = FillCardAttributes("Carta 2", card2);
    
    //Mostra os atributos que o jogador preencheu
    LineBreak(1);
    printf("CARTAS INFORMADAS:");
    LineBreak(2);
    ShowCardAttributes(card1);
    LineBreak(2);
    ShowCardAttributes(card2);
    LineBreak(2);

    ShowCompareOptions();
    
    int preferredOption[2];

    for(int i = 0; i < 2; i++)
    {
        printf(i == 0 ? "Digite o número correspondente ao atributo a ser comparado: " : "Ótimo! Escolha só mais uma opção para comparar: ");
        scanf("%d", &preferredOption[i]);
    }
    
    LineBreak(1);
    CompareCards(preferredOption, card1, card2);
    LineBreak(2);

    printf("Fim de jogo");
    LineBreak(2);

    return 0;
}