# EOS Unit 2 — OS Level Programming in C++

Deze opdracht is individueel. De opdracht is het maken van een paar simpele utilities die je als deel van een pipeline kan inzetten, en hierbij gebruik te maken van OS calls. Voor het compilen van de utilities gebruiken we GNU Make en (optioneel) CMake. Je moet zowel je code als de Makefiles aan je docent laten zien.

## Opdracht 0
Tijdens de vorige twee practica hebben we uitvoerig gebruik gemaakt van command line utilities op Linux. Deze programma's volgen allemaal de Unix filosofie: doe een taak, maar doe die goed. De reden dat dit zo krachtig is, is dat de kleine programma's gecombineerd kunnen worden om ingewikkelde problemen te automatiseren. Dit noemen we compositie, en kunnen we realiseren met behulp van standaard-invoer en standaard-uitvoer.
Maak een simpele utility die invoer leest vanuit `std::cin`, hier iets mee doet, en het resultaat uitvoert naar `std::cout`. Het maakt niet uit wat er met de input gebeurt, zolang deze (1) herkenbaar verandert en (2) de utility voor de hele invoer werkt (dus tot aan de EOF). Compile je utility, en laat zien dat deze te combineren is met andere utilities doormiddel van pipes en IO redirection. Eventuele extra output wordt teruggegeven met behulp van `std::cerr` of `std::clog` (whichever meer van toepassing is). Maak een Makefile om je bestand te compileren.
**TODO:** Command Line Argumenten

## Opdracht 1
Bij het programmeren, zelfs in een low-level taal als C++, nemen we vaak een hoop functionaliteit voor lief. We kunnen bijvoorbeeld bestanden inlezen of tekst printen op manieren die op de meeste systemen hetzelfde werken. Onder water is hier tussen bijvoorbeeld Linux en Windows echter heel andere code voor nodig. De standaard libraries bevatten algemene functies, die dit op het niveau van het besturingssysteem voor ons doen; wij gaan kijken hoe we Linux direct kunnen vragen om bepaalde functionaliteit.

We gaan een simpele shell maken, die op een aantal commando's kan reageren. Hiervoor maken we zoveel mogelijk gebruik van de Linux system calls. Gebruik `shell.cc` als uitgangspunt, en definieer voor elk commando een functie in een eigen bestand. Maak een Makefile om je shell te compileren. 

De shell moet bij opstarten een configuratiebestand inlezen, waarin een enkele string staat. Deze string bevat het prompt (iedere invoerregel begint met het prompt om aan te geven dat de gebruiker invoer kan geven). Dit bestand wordt ingelezen met behulp van `read`. Daarnaast moet de shell tenminste de volgende commando's ondersteunen:
- `new_file`: deze vraagt de gebruiker om twee strings: eerst een enkele regel, de bestandsnaam, en daarna een tekst, die afgesloten wordt met `<EOF>`. De gegeven tekst wordt in een nieuw bestand geschreven met de gekozen bestandsnaam. Tussen elke regel bevindt zich lege ruimte: na een regel van 5 karakters worden 5 karakters overgeslagen voordat de volgende regel toegevoegd wordt. Gebruik hiervoor de system calls `creat`, `lseek` en `write`.
- `ls`: deze spawnt een nieuw proces (`ls -la`) en print het resultaat. Gebruik hiervoor de system calls `fork`, `exec` en `wait`.
- `find`: deze vraagt om een string, en spawnt vervolgens twee nieuwe processen, (`find .`) en (`grep string`). De processen worden met een pipe verbonden zodat `grep` de output van `find` filtert alvorens deze te printen. Gebruik hiervoor de system calls `fork`, `exec`, `wait` en `pipe`.
**TODO: In plaats van ls een opdracht met langer durende fork? Interactief programma? Wachten op dood kind?"

## Opdracht 2
