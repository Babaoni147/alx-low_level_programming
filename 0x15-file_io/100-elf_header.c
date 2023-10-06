#include "main.h"

void check_elf(unsigned char *e_ident);
void magic(unsigned char *e_ident);
void class(unsigned char *e_ident);
void data(unsigned char *e_ident);
void version(unsigned char *e_ident);
void abi(unsigned char *e_ident);
void osabi(unsigned char *e_ident);
void type(unsigned int e_type, unsigned char *e_ident);
void entry(unsigned long int e_entry, unsigned char *e_ident);
void elf_close(int elf);

/**
 * check_elf - Function that checks for elf files
 * @e_ident: Pointer to elf file
 * Return: 0 (Success) else exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_ident[idx] != 127 &&
		    e_ident[idx] != 'E' &&
		    e_ident[idx] != 'L' &&
		    e_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}


/**
 * magic - Function that print the magic numbers of an ELF header
 * @e_ident: Pointer to elf file
 */
void magic(unsigned char *e_ident)
{
	int idx;

	printf(" Magic: ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", e_ident[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * class - Function that prints the class of an ELF file in elf.
 * @e_ident: pointer to elf file
 */
void class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * data - function that prints the data of an ELF file in elf.h
 * @e_ident: Pointer to elf file
 */
void data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * version - Function that print the version of an ELF file in elf.h
 * @e_ident: Pointer to elf file
 */
void version(unsigned char *e_ident)
{
	printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_NONE:
		printf(" (none)\n");
		break;
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}



/**
 * osabi - Function that prints the OS/ABI of EFL file in elf.h
 * @e_ident: Pointer to elf file
 */
void osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * type - Function that print the type of an ELF file in elf.h
 * @e_type: The elf file type
 * @e_ident: Pointer to elf file
 */
void type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * abi - function that prints the ABI version of an ELF file in elf.h
 * @e_ident: Pointer to elf file
 */
void abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * entry - function that print the entry point of an ELF file in elf.h
 * @e_entry: The address of the ELE entey point
 * @e_ident: Pointer to elf file
 */
void entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point addresss: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * elf_close - Function that close an ELF file
 * @elf_fd: File descriptor of the ELF file
 */
void elf_close(int elf_fd)
{
	if (close(elf_fd) == -1)
	{
		dprintf(STDERR_FILENO, "ERROR: Can't close fd %d\n", elf_fd);
		exit(98);
	}
}

/**
 * main - Function that displays the information contained in the
 * elf.h at the start of an elf file
 * @argc: The number of arguments
 * @argv: Array of pointer to arguments
 * Return: 0 (Success)
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int op, rd;

	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_close(op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(op, header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(header);
		elf_close(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	magic(header->e_ident);
	class(header->e_ident);
	data(header->e_ident);
	version(header->e_ident);
	osabi(header->e_ident);
	abi(header->e_ident);
	type(header->e_type, header->e_ident);
	entry(header->e_entry, header->e_ident);

	free(header);
	elf_close(op);
	return (0);
}

