#ifndef _KERNEL_ELF_H
#define _KERNEL_ELF_H




/*
   Kernel-ELF transactions and loaded and linking and what not,
   go here.
*/



#define EI_NIDENT	16

// Elf file types

#define ET_NONE			0     
#define ET_REL			1     
#define ET_EXEC			2
#define ET_DYN			3
#define ET_CORE			4
#define ET_LOPROC		0xff00
#define ET_HIPROC		0xffff

// Elf machine types

#define EM_NONE			0
#define EM_M32			1
#define EM_SPARC		2
#define EM_386			3
#define EM_68K			4
#define EM_88K			5
#define EM_860			7
#define EM_MIPS			8

// Elf version

#define EV_NONE			0
#define EV_CURRENT		1

// -----------------------------    ELF Magic numbers
//  An ELF file should have MAG0,MAG1,MAG2,MAG3
//  set to 0x7f,'E','L','F' respectively
//

#define EI_MAG0			0
#define EI_MAG1			1
#define EI_MAG2			2
#define EI_MAG3			3
#define EI_CLASS		4
#define EI_DATA			5
#define EI_VERSION		6
#define EI_PAD			7


  //                     ELF CLASSES ------------
  
#define ELFCLASSNONE		0
#define ELFCLASS32		1
#define ELFCLASS64		2

  //                     ELF DATAS ----------------------------

#define ELFDATANONE		0
#define ELFDATA2LSB		1
#define ELFDATA2MSB		2


// ------------------ ELF SECTION HEADERS

#define SHN_UNDEF		0
#define SHN_LORESERVE		0xff00
#define SHN_LOPROC		0xff00
#define SHN_HIPROC		0xff1f
#define SHN_ABS			0xfff1
#define SHN_COMMON		0xfff2
#define SHN_HIRESERVE		0xffff
  

#define SHT_NULL		0
#define SHT_PROGBITS		1
#define SHT_SYMTAB		2
#define SHT_STRTAB		3
#define SHT_RELA		4
#define SHT_HASH		5
#define SHT_DYNAMIC		6
#define SHT_NOTE 		7
#define SHT_NOBITS		8
#define SHT_REL			9
#define SHT_SHLIB		10
#define SHT_DYNSYM		11
#define SHT_LOPROC		0x70000000
#define SHT_HIPROC		0x7fffffff
#define SHT_LOUSER		0x80000000
#define SHT_HIUSER		0xffffffff


// ---------------- ELF Relocation types

#define R_386_NONE		0
#define R_386_32		1
#define R_386_PC32		2
#define R_386_GOT32		3
#define R_386_PLT32		4
#define R_386_COPY		5
#define R_386_GLOB_DAT		6
#define R_386_JMP_SLOT		7
#define R_386_RELATIVE		8
#define R_386_GOTOFF		9
#define R_386_GOTPC		10

// ----------------- ELF PROGRAM SEGMENT TYPES

#define PT_NULL			0
#define PT_LOAD			1
#define PT_DYNAMIC		2
#define PT_INTERP		3
#define PT_NOTE			4
#define PT_SHLIB		5
#define PT_PHDR	 		6
#define PT_LOPROC		0x70000000
#define PT_HIPROC		0x7fffffff


typedef unsigned long Elf32_Addr;
typedef unsigned short Elf32_Half;
typedef unsigned long Elf32_Off;
typedef signed long Elf32_Sword;
typedef unsigned long Elf32_Word;


typedef struct
{
   unsigned char	e_ident[EI_NIDENT];
   Elf32_Half		e_type;
   Elf32_Half		e_machine;
   Elf32_Word		e_version;
   Elf32_Addr		e_entry;
   Elf32_Off		e_phoff;
   Elf32_Off		e_shoff;
   Elf32_Word		e_flags;
   Elf32_Half		e_ehsize;
   Elf32_Half		e_phentsize;
   Elf32_Half		e_phnum;
   Elf32_Half		e_shentsize;
   Elf32_Half		e_shnum;
   Elf32_Half		e_shstrndx;

} ELF32_Ehdr;


typedef struct
{
   Elf32_Word		sh_name;
   Elf32_Word		sh_type;
   Elf32_Word		sh_flags;
   Elf32_Addr		sh_addr;
   Elf32_Off		sh_offset;
   Elf32_Word		sh_size;
   Elf32_Word		sh_link;
   Elf32_Word		sh_info;
   Elf32_Word		sh_addralign;
   Elf32_Word		sh_entsize;
} ELF32_Shdr;


typedef struct
{
   Elf32_Word		st_name;
   Elf32_Addr		st_value;
   Elf32_Word		st_size;
   unsigned char	st_info;
   unsigned char	st_other;
   Elf32_Half		st_shndx;
} ELF32_Sym;


typedef struct
{
   Elf32_Addr		r_offset;
   Elf32_Word		r_info;
} ELF32_Rel;

typedef struct
{
   Elf32_Addr		r_offset;
   Elf32_Word		r_info;
   Elf32_Sword		r_added;
} ELF32_Rela;

typedef struct
{
   Elf32_Word		p_type;
   Elf32_Off		p_offset;
   Elf32_Addr		p_vaddr;
   Elf32_Addr		p_paddr;
   Elf32_Word		p_filesz;
   Elf32_Word		p_memsz;
   Elf32_Word		p_flags;
   Elf32_Word		p_align;
} ELF32_Phdr;



#endif


