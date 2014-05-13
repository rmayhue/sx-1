/** @file cmd_cluster.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.6
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMD_CLUSTER_H
#define CMD_CLUSTER_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CLUSTER_CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define CLUSTER_CMDLINE_PARSER_PACKAGE "sxadm"
#endif

#ifndef CLUSTER_CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CLUSTER_CMDLINE_PARSER_PACKAGE_NAME "sxadm"
#endif

#ifndef CLUSTER_CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CLUSTER_CMDLINE_PARSER_VERSION VERSION
#endif

/** @brief Where the command line options are stored */
struct cluster_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  const char *new_help; /**< @brief Creates a new SX cluster with a local node help description.  */
  const char *mod_help; /**< @brief Modifies an existing SX cluster help description.  */
  const char *info_help; /**< @brief Shows status and details of a running cluster help description.  */
  const char *force_gc_help; /**< @brief Force a garbage collection cycle on all noeds help description.  */
  char * node_dir_arg;	/**< @brief Path to the node directory.  */
  char * node_dir_orig;	/**< @brief Path to the node directory original value given at command line.  */
  const char *node_dir_help; /**< @brief Path to the node directory help description.  */
  char * key_arg;	/**< @brief File containing a pre-generated admin authentication token or stdin if \"-\" is given (default autogenerate token)..  */
  char * key_orig;	/**< @brief File containing a pre-generated admin authentication token or stdin if \"-\" is given (default autogenerate token). original value given at command line.  */
  const char *key_help; /**< @brief File containing a pre-generated admin authentication token or stdin if \"-\" is given (default autogenerate token). help description.  */
  char * ssl_ca_file_arg;	/**< @brief SSL CA certificate file of the SX cluster (same file as in httpd configuration).  */
  char * ssl_ca_file_orig;	/**< @brief SSL CA certificate file of the SX cluster (same file as in httpd configuration) original value given at command line.  */
  const char *ssl_ca_file_help; /**< @brief SSL CA certificate file of the SX cluster (same file as in httpd configuration) help description.  */
  char * config_dir_arg;	/**< @brief Path to SX configuration directory.  */
  char * config_dir_orig;	/**< @brief Path to SX configuration directory original value given at command line.  */
  const char *config_dir_help; /**< @brief Path to SX configuration directory help description.  */
  const char *batch_mode_help; /**< @brief Turn off interactive confirmations and assume yes for all questions help description.  */
  int debug_flag;	/**< @brief Enable debug messages (default=off).  */
  const char *debug_help; /**< @brief Enable debug messages help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int new_given ;	/**< @brief Whether new was given.  */
  unsigned int mod_given ;	/**< @brief Whether mod was given.  */
  unsigned int info_given ;	/**< @brief Whether info was given.  */
  unsigned int force_gc_given ;	/**< @brief Whether force-gc was given.  */
  unsigned int node_dir_given ;	/**< @brief Whether node-dir was given.  */
  unsigned int key_given ;	/**< @brief Whether key was given.  */
  unsigned int ssl_ca_file_given ;	/**< @brief Whether ssl-ca-file was given.  */
  unsigned int config_dir_given ;	/**< @brief Whether config-dir was given.  */
  unsigned int batch_mode_given ;	/**< @brief Whether batch-mode was given.  */
  unsigned int debug_given ;	/**< @brief Whether debug was given.  */

  char **inputs ; /**< @brief unamed options (options without names) */
  unsigned inputs_num ; /**< @brief unamed options number */
  int MODE_group_counter; /**< @brief Counter for group MODE */
} ;

/** @brief The additional parameters to pass to parser functions */
struct cluster_cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure cluster_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure cluster_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *cluster_args_info_purpose;
/** @brief the usage string of the program */
extern const char *cluster_args_info_usage;
/** @brief the description string of the program */
extern const char *cluster_args_info_description;
/** @brief all the lines making the help output */
extern const char *cluster_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cluster_cmdline_parser (int argc, char **argv,
  struct cluster_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cluster_cmdline_parser_ext() instead
 */
int cluster_cmdline_parser2 (int argc, char **argv,
  struct cluster_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cluster_cmdline_parser_ext (int argc, char **argv,
  struct cluster_args_info *args_info,
  struct cluster_cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cluster_cmdline_parser_dump(FILE *outfile,
  struct cluster_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cluster_cmdline_parser_file_save(const char *filename,
  struct cluster_args_info *args_info);

/**
 * Print the help
 */
void cluster_cmdline_parser_print_help(void);
/**
 * Print the version
 */
void cluster_cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cluster_cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cluster_cmdline_parser_params_init(struct cluster_cmdline_parser_params *params);

/**
 * Allocates dynamically a cluster_cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cluster_cmdline_parser_params structure
 */
struct cluster_cmdline_parser_params *cluster_cmdline_parser_params_create(void);

/**
 * Initializes the passed cluster_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cluster_cmdline_parser_init (struct cluster_args_info *args_info);
/**
 * Deallocates the string fields of the cluster_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cluster_cmdline_parser_free (struct cluster_args_info *args_info);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cluster_cmdline_parser_required (struct cluster_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMD_CLUSTER_H */
