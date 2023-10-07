#include "main.h"
#include <elf.h>

void more_osabi(Elf64_Ehdr h);
void magic(Elf64_Ehdr h);
void class(Elf64_Ehdr h);
void data(Elf64_Ehdr h);
void version(Elf64_Ehdr h);
void abi(Elf64_Ehdr h);
void osabi(Elf64_Ehdr h);
void type(Elf64_Ehdr h);
void entry(Elf64_Ehdr h);

/**
 * magic - Function that print the magic numbers of an ELF header
 * @h: Elf header structure
 */
void magic(Elf64_Ehdr h)
{
	int idx;

	printf(" Magic: ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%2.2x%s", h.e_ident[idx], idx == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * class - Function that prints the class of an ELF file in elf.
 * @h: ELF header structure
 */
void class(Elf64_Ehdr h)
{
	printf(" Class:				     ");

	switch (h.e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", h.e_ident[EI_CLASS]);
	}
}

/**
 * data - function that prints the data of an ELF file in elf.h
 * @h: Elf header structure
 */
void data(Elf64_Ehdr h)
{
	printf(" Data:				     ");

	switch (h.e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", h.e_ident[EI_CLASS]);
	}
}

/**
 * version - Function that print the version of an ELF file in elf.h
 * @h: Elf header structure
 */
void version(Elf64_Ehdr h)
{
	printf(" Version:			     %d", h.e_ident[EI_VERSION]);

	switch (h.e_ident[EI_VERSION])
	{
	case EV_NONE:
		printf("%s", "");
		break;
	case EV_CURRENT:
		printf(" (current)");
		break;
		break;
	}
	printf("\n");
}

/**
 * osabi - Function that prints the OS/ABI of EFL file in elf.h
 * @h: Elf header structure
 */
void osabi(Elf64_Ehdr h)
{
	printf(" OS/ABI:			     ");

	switch (h.e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	default:
		printf("unknown: %x>\n", h.e_ident[EI_OSABI]);
	}
}

/**
 * more_osabi - prints more ELF osabi
 * @h: Elf header file
 */
void more_osabi(Elf64_Ehdr h)
{
	printf(" OS/ABI:                              ");

	switch (h.e_ident[EI_OSABI])
	{
	case ELFOSABI_MODESTO:
		printf("Novell - Modesto\n");
		break;
	case ELFOSABI_OPENBSD:
		printf("UNIX - OpenBSD\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	default:
		printf("<unknown: %x>", h.e_ident[EI_OSABI]);
	}
}

/**
 * type - Function that print the type of an ELF file in elf.h
 * @h: Elf header file
 */
void type(Elf64_Ehdr h)
{
	char *t = (char *)&h.e_type;
	int p = 0;

	printf(" Type:				     ");
	if (h.e_ident[EI_DATA] == ELFDATA2MSB)
		p = 1;

	switch (t[p])
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable File)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	default:
		printf("<unknown: %x>\n", t[p]);
	}
}

/**
 * abi - function that prints the ABI version of an ELF file in elf.h
 * @h: Elf header file
 */
void abi(Elf64_Ehdr h)
{
	printf(" ABI Version:			     %d\n",
		h.e_ident[EI_ABIVERSION]);
}

/**
 * entry - function that print the entry point of an ELF file in elf.h
 * @h: Elf header file
 */
void entry(Elf64_Ehdr h)
{
	int i = 0, l = 0;
	unsigned char *t = (unsigned char *)&h.e_entry;

	printf(" Entry point addresss: 0x");

	if (h.e_ident[EI_DATA] == ELFDATA2MSB)
	{
		i = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!t[i])
			i--;
		printf("%x", t[i--]);
		for (; i >= 0; i--)
			printf("%02x", t[i]);
		printf("\n");
	}
	else
	{
		i = 0;
		l = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!t[i])
			i++;
		printf("%x", t[i++]);
		for (; i <= l; i++)
			printf("%02x", t[i]);
		printf("\n");
	}
}


/**
 * main - Function that displays elf.h content
 * @ac: The number of arguments
 * @av: Array of pointer to arguments
 * Return: 0 (Success)
 */
int main(int ac, char **av)
{
	Elf64_Ehdr h;
	int op;
	ssize_t rd;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	}
	op = open(av[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	rd = read(op, &h, sizeof(h));
	if (rd < 1 || rd != sizeof(h))
	{
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", av[1]), exit(98);
	}
	if (h.e_ident[0] == 0x7f && h.e_ident[1] == 'E' && h.e_ident[2] == 'L'
			 && h.e_ident[3] == 'F')
	{
		printf("EFL Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: No such file %s\n", av[1]), exit(98);
	}

	magic(h);
	class(h);
	data(h);
	version(h);
	osabi(h);
	abi(h);
	type(h);
	entry(h);
	if (close(op))
		dprintf(STDERR_FILENO, "Error closing file: %d\n", op), exit(98);
	return (0);
}
