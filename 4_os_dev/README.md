---
title: "EOS Unit 4 — OS Development"
keywords: [EOS]
---

# EOS Unit 4 — OS Development

In de laatste opdracht gaan we daadwerkelijk wat aan operating systems sleutelen.

## Opdracht 0
De System calls die we in Unit 2 Opdracht 2 hebben gezien worden allemaal door de Linux Kernel geleverd, net als [een flinke lijst](https://www.tutorialspoint.com/unix_system_calls/index.htm) andere calls. Door de Linux Kernel aan te passen, is het mogelijk om zelf system calls toe te voegen.

- **Download de source van je kernel.** (hoe dan?)
- **Laad je bestaande kernel configuratie met `zcat /proc/config.gz > .config` (in de root map van je kernel source).** Deze configuratie kunnen we als basis gebruiken om onze eigen kernel te compileren.
- **Open `.config` en vervang de waarde van `CONFIG_LOCALVERSION` naar `-EOS`.** Zo is je kernel te onderscheiden van de reguliere kernel.
- **Voeg een system-call to aan de system call table: open het bestand `arch/x86/entry/syscalls/syscall_64.tbl` en voeg een regel toe met het eerste vrij getal (bij mij is dit 548, maar dit hangt van je versie af): `548	common	eos	sys_eos`.** `eos` is de naam waarmee we de system call straks aan kunnen roepen. `sys_eos` is de interne naam, doorgaans zijn deze van de vorm `sys_naam`.
- ***Open `kernel/sys.c` en voeg een functie `eos` toe die een bericht print.*** Hiervoor gebruiken we de `SYSCALL_DEFINE0` macro (een macro werkt vergelijkbaar met een functie, maar wordt tijdens het compilen al uitgevoerd; het resultaat wordt in de kernel opgeslagen, niet de functie zelf) om een sytem call zonder argumenten te maken. Zoek in de kernel source naar een voorbeeld van een `SYSCALL_DEFINE0`, of een andere `SYSCALL_DEFINEX` (`X` staat voor het aantal argumenten van de syscall). De functie hoeft niet meer te doen dan een simpele `printk(KERN_INFO "Never gonna give you up")`. Hoewel de kernel in C is geschreven zou dit met je C++ kennis te doen moeten zijn (zolang je geen objecten of geavanceerde features gebruikt).
- ***Compile de kernel en installeer deze.***
- ***Reboot je Pi/VM/Laptop en maak een `test.cc` waarin je in `main` de syscall aanroept. Voer het programma uit en kijk met `dmesg | tail` of je boodschap is aangekomen.***

## Opdracht 1
Opdracht 1 is nog in ontwikkeling.
