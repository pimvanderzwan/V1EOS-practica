---
title: "EOS Unit 1 — OS Level Programming in C++"
keywords: [EOS]
---

# EOS Unit 1 — OS Level Programming in C++

Deze opdracht is individueel. De opdracht is het maken van een paar simpele utilities die je als deel van een pipeline kan inzetten, en hierbij gebruik te maken van OS calls. Je kunt de code op je normale systeem of op Linux (bijvoorbeeld in de VM) schrijven, maar voor het compileren en uitvoeren moet je sowieso Linux gebruiken. Voor het op Linux compilen van je code gebruik je `g++`, bijvoorbeeld `g++ file.cc -o file`. Als dit goed compileert kun je dit daarna starten met `./file`. Je levert je code in via een link naar een commit op GitHub. Je kunt [deze repo](https://github.com/Peikos/V1EOS-practica) als uitgangspunt gebruiken, bijvoorbeeld door een fork te maken en hierin te werken.

## Opdracht 0
Tijdens de vorige twee practica hebben we uitvoerig gebruik gemaakt van command line utilities op Linux. Deze programma's volgen allemaal de Unix filosofie: doe één taak, maar doe die goed. De reden dat dit zo krachtig is, is dat de kleine programma's gecombineerd kunnen worden om ingewikkelde problemen te automatiseren. Dit noemen we compositie, en kunnen we realiseren met behulp van standaard-invoer en standaard-uitvoer.
Maak een simpele utility die invoer leest vanuit `std::cin`, hier iets mee doet, en het resultaat uitvoert naar `std::cout`. Geef de utility (teminste) een argument dat de werking van de utility beïnvloed. Het maakt niet uit wat er met de input gebeurt, zolang deze (1) herkenbaar en afhankelijk van het argument verandert, en (2) de utility voor de hele invoer werkt (dus tot aan de EOF). Compile je utility, en laat zien dat deze te combineren is met andere utilities doormiddel van pipes en IO redirection. Eventuele extra output wordt teruggegeven met behulp van `std::cerr` of `std::clog` (whichever meer van toepassing is).

### Enkele suggesties
- Een [Caesarcijfer](https://nl.wikipedia.org/wiki/Caesarcijfer) waarbij het aantal plaatsen met een command-line argument kan worden aangegeven.
- Een vertaler voor [pig-latin](https://nl.wikipedia.org/wiki/Pig_Latin), waarbij de uitgang "-ay" met een argument aangepast kan worden.
- Een teller die telt hoe vaak ieder woord of karakter dat als argument wordt meegegeven voorkomt in de input.

## Opdracht 1
Bij het programmeren, zelfs in een low-level taal als C++, nemen we vaak een hoop functionaliteit voor lief. We kunnen bijvoorbeeld bestanden inlezen of tekst printen op manieren die op de meeste systemen hetzelfde werken. Onder water is hier tussen bijvoorbeeld Linux en Windows echter heel andere code voor nodig. De standaard libraries bevatten algemene functies, die dit op het niveau van het besturingssysteem voor ons doen; wij gaan kijken hoe we Linux direct kunnen vragen om bepaalde functionaliteit.

We gaan een simpele shell maken, die op een aantal commando's kan reageren. Hiervoor maken we zoveel mogelijk gebruik van de Linux system calls. Je kunt het bestand `shell.cc` uit [deze repository](https://github.com/Peikos/V1EOS-practica) gebruiken als uitgangspunt. 

De shell moet bij opstarten een configuratiebestand inlezen, waarin een enkele string staat. Deze string bevat het prompt (iedere invoerregel begint met het prompt om aan te geven dat de gebruiker invoer kan geven). Dit bestand wordt ingelezen met behulp van `read`. Daarnaast moet de shell tenminste de volgende commando's ondersteunen:

- `new_file`: deze vraagt de gebruiker om twee strings: eerst een enkele regel, de bestandsnaam, en daarna een tekst, die afgesloten wordt met `<EOF>`. De gegeven tekst wordt in een nieuw bestand geschreven met de gekozen bestandsnaam. Gebruik hiervoor de system calls `creat`, `open` en `write`.
- `ls`: deze spawnt een nieuw proces (`ls -la`) en print het resultaat. Gebruik hiervoor de system calls `fork`, `exec` en `wait`.
- `find`: deze vraagt om een string, en spawnt vervolgens twee nieuwe processen, (`find .`) en (`grep string`). De processen worden met een pipe verbonden zodat `grep` de output van `find` filtert alvorens deze te printen. Gebruik hiervoor de system calls `fork`, `exec`, `wait` en `pipe`.
- `python`: hiermee wordt een interactieve Python-interpreter gestart. De shell wacht tot Python dood is voordat het de exit-code print en zelf verder gaat. Gebruik hiervoor de system calls `fork`, `exec` en `wait`.

## Opdracht 2
Zoek de werking van de system-calls `read`, `write` en `lseek` op. Gebruik deze om een programmat te schrijven dat op basis van een `int`-argument een bestand op een bepaalde manier shuffelt. Als het programma bijvoorbeeld met het getal `4` aangeroepen wordt zal het eerst karakter 0 van het input-bestand opzoeken en deze wegschrijven naar het uitvoerbestand. Vervolgens wordt karakter 4 opgezocht en weggeschreven, en dan 8, en zo verder. Als het programma aan het einde van de input-file komt gaat het verder met tellen vanaf 0, totdat je precies op het eerste karakter (0) uitkomt. Bij een input-bestand met 9 karakters worden de volgende karakters weggeschreven: [0, 4, 8, 12-9=3, 7, 11-9=2, 6, 10-9=1, 5, 9-9=0]. Gebruik de bovengenoemde system-calls om door het bestand te lopen; je kunt hiervoor de "modulo" operator `%` gebruiken om makkelijk het "voorbij het einde gaan" te programmeren.
