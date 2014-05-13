/*
  File autogenerated by gengetopt version 2.22.6
  generated with the following command:
  gengetopt --unamed-opts --no-handle-version --no-handle-error --file-name=cmd_cluster --func-name=cluster_cmdline_parser --arg-struct-name=cluster_args_info

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include <getopt.h>

#include "cmd_cluster.h"

const char *cluster_args_info_purpose = "";

const char *cluster_args_info_usage = "Usage: \nsxadm cluster --new [options] NODE sx://[profile@]cluster\nsxadm cluster --mod [options] NODE [NODE ...] sx://[profile@]cluster";

const char *cluster_args_info_versiontext = "";

const char *cluster_args_info_description = "";

const char *cluster_args_info_help[] = {
  "  -h, --help              Print help and exit",
  "  -V, --version           Print version and exit",
  "\n Group: MODE",
  "  -N, --new               Creates a new SX cluster with a local node",
  "  -M, --mod               Modifies an existing SX cluster",
  "  -I, --info              Shows status and details of a running cluster",
  "  -G, --force-gc          Force a garbage collection cycle on all noeds",
  "\nNew cluster options:",
  "  -d, --node-dir=PATH     Path to the node directory",
  "  -k, --key=PATH          File containing a pre-generated admin authentication\n                            token or stdin if \"-\" is given (default\n                            autogenerate token).",
  "      --ssl-ca-file=PATH  SSL CA certificate file of the SX cluster (same file\n                            as in httpd configuration)",
  "\nCommon options:",
  "  -c, --config-dir=PATH   Path to SX configuration directory",
  "  -b, --batch-mode        Turn off interactive confirmations and assume yes for\n                            all questions",
  "  -D, --debug             Enable debug messages  (default=off)",
  "\nNODE definition is a string in the form\n<capacity>/<address>/[internal_address]/[node_uuid]\nExamples:\n\"100G/192.0.2.1\": 100 GiB node listening on address 192.0.2.1 with\nautomatically assigned uuid\n\"2T/192.0.2.2/198.51.100.1\": 2 TiB cluster using address 192.0.2.2 for public\naccess and address 198.51.100.1 for internal communication\n\"123gb/203.0.113.1//e4d2c9ea-b2b1-43c4-851d-39e86a7a377c\": 123 GiB cluster on\naddress 203.0.113.1 and uuid as specified",
    0
};

typedef enum {ARG_NO
  , ARG_FLAG
  , ARG_STRING
} cluster_cmdline_parser_arg_type;

static
void clear_given (struct cluster_args_info *args_info);
static
void clear_args (struct cluster_args_info *args_info);

static int
cluster_cmdline_parser_internal (int argc, char **argv, struct cluster_args_info *args_info,
                        struct cluster_cmdline_parser_params *params, const char *additional_error);

static int
cluster_cmdline_parser_required2 (struct cluster_args_info *args_info, const char *prog_name, const char *additional_error);

static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct cluster_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->new_given = 0 ;
  args_info->mod_given = 0 ;
  args_info->info_given = 0 ;
  args_info->force_gc_given = 0 ;
  args_info->node_dir_given = 0 ;
  args_info->key_given = 0 ;
  args_info->ssl_ca_file_given = 0 ;
  args_info->config_dir_given = 0 ;
  args_info->batch_mode_given = 0 ;
  args_info->debug_given = 0 ;
  args_info->MODE_group_counter = 0 ;
}

static
void clear_args (struct cluster_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->node_dir_arg = NULL;
  args_info->node_dir_orig = NULL;
  args_info->key_arg = NULL;
  args_info->key_orig = NULL;
  args_info->ssl_ca_file_arg = NULL;
  args_info->ssl_ca_file_orig = NULL;
  args_info->config_dir_arg = NULL;
  args_info->config_dir_orig = NULL;
  args_info->debug_flag = 0;
  
}

static
void init_args_info(struct cluster_args_info *args_info)
{


  args_info->help_help = cluster_args_info_help[0] ;
  args_info->version_help = cluster_args_info_help[1] ;
  args_info->new_help = cluster_args_info_help[3] ;
  args_info->mod_help = cluster_args_info_help[4] ;
  args_info->info_help = cluster_args_info_help[5] ;
  args_info->force_gc_help = cluster_args_info_help[6] ;
  args_info->node_dir_help = cluster_args_info_help[8] ;
  args_info->key_help = cluster_args_info_help[9] ;
  args_info->ssl_ca_file_help = cluster_args_info_help[10] ;
  args_info->config_dir_help = cluster_args_info_help[12] ;
  args_info->batch_mode_help = cluster_args_info_help[13] ;
  args_info->debug_help = cluster_args_info_help[14] ;
  
}

void
cluster_cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CLUSTER_CMDLINE_PARSER_PACKAGE_NAME) ? CLUSTER_CMDLINE_PARSER_PACKAGE_NAME : CLUSTER_CMDLINE_PARSER_PACKAGE),
     CLUSTER_CMDLINE_PARSER_VERSION);

  if (strlen(cluster_args_info_versiontext) > 0)
    printf("\n%s\n", cluster_args_info_versiontext);
}

static void print_help_common(void) {
  cluster_cmdline_parser_print_version ();

  if (strlen(cluster_args_info_purpose) > 0)
    printf("\n%s\n", cluster_args_info_purpose);

  if (strlen(cluster_args_info_usage) > 0)
    printf("\n%s\n", cluster_args_info_usage);

  printf("\n");

  if (strlen(cluster_args_info_description) > 0)
    printf("%s\n\n", cluster_args_info_description);
}

void
cluster_cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (cluster_args_info_help[i])
    printf("%s\n", cluster_args_info_help[i++]);
}

void
cluster_cmdline_parser_init (struct cluster_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);

  args_info->inputs = 0;
  args_info->inputs_num = 0;
}

void
cluster_cmdline_parser_params_init(struct cluster_cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cluster_cmdline_parser_params *
cluster_cmdline_parser_params_create(void)
{
  struct cluster_cmdline_parser_params *params = 
    (struct cluster_cmdline_parser_params *)malloc(sizeof(struct cluster_cmdline_parser_params));
  cluster_cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cluster_cmdline_parser_release (struct cluster_args_info *args_info)
{
  unsigned int i;
  free_string_field (&(args_info->node_dir_arg));
  free_string_field (&(args_info->node_dir_orig));
  free_string_field (&(args_info->key_arg));
  free_string_field (&(args_info->key_orig));
  free_string_field (&(args_info->ssl_ca_file_arg));
  free_string_field (&(args_info->ssl_ca_file_orig));
  free_string_field (&(args_info->config_dir_arg));
  free_string_field (&(args_info->config_dir_orig));
  
  
  for (i = 0; i < args_info->inputs_num; ++i)
    free (args_info->inputs [i]);

  if (args_info->inputs_num)
    free (args_info->inputs);

  clear_given (args_info);
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  FIX_UNUSED (values);
  if (arg) {
    fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cluster_cmdline_parser_dump(FILE *outfile, struct cluster_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CLUSTER_CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->new_given)
    write_into_file(outfile, "new", 0, 0 );
  if (args_info->mod_given)
    write_into_file(outfile, "mod", 0, 0 );
  if (args_info->info_given)
    write_into_file(outfile, "info", 0, 0 );
  if (args_info->force_gc_given)
    write_into_file(outfile, "force-gc", 0, 0 );
  if (args_info->node_dir_given)
    write_into_file(outfile, "node-dir", args_info->node_dir_orig, 0);
  if (args_info->key_given)
    write_into_file(outfile, "key", args_info->key_orig, 0);
  if (args_info->ssl_ca_file_given)
    write_into_file(outfile, "ssl-ca-file", args_info->ssl_ca_file_orig, 0);
  if (args_info->config_dir_given)
    write_into_file(outfile, "config-dir", args_info->config_dir_orig, 0);
  if (args_info->batch_mode_given)
    write_into_file(outfile, "batch-mode", 0, 0 );
  if (args_info->debug_given)
    write_into_file(outfile, "debug", 0, 0 );
  

  i = EXIT_SUCCESS;
  return i;
}

int
cluster_cmdline_parser_file_save(const char *filename, struct cluster_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CLUSTER_CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cluster_cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cluster_cmdline_parser_free (struct cluster_args_info *args_info)
{
  cluster_cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

static void
reset_group_MODE(struct cluster_args_info *args_info)
{
  if (! args_info->MODE_group_counter)
    return;
  
  args_info->new_given = 0 ;
  args_info->mod_given = 0 ;
  args_info->info_given = 0 ;
  args_info->force_gc_given = 0 ;

  args_info->MODE_group_counter = 0;
}

int
cluster_cmdline_parser (int argc, char **argv, struct cluster_args_info *args_info)
{
  return cluster_cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cluster_cmdline_parser_ext (int argc, char **argv, struct cluster_args_info *args_info,
                   struct cluster_cmdline_parser_params *params)
{
  int result;
  result = cluster_cmdline_parser_internal (argc, argv, args_info, params, 0);

  return result;
}

int
cluster_cmdline_parser2 (int argc, char **argv, struct cluster_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cluster_cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cluster_cmdline_parser_internal (argc, argv, args_info, &params, 0);

  return result;
}

int
cluster_cmdline_parser_required (struct cluster_args_info *args_info, const char *prog_name)
{
  int result = EXIT_SUCCESS;

  if (cluster_cmdline_parser_required2(args_info, prog_name, 0) > 0)
    result = EXIT_FAILURE;

  return result;
}

int
cluster_cmdline_parser_required2 (struct cluster_args_info *args_info, const char *prog_name, const char *additional_error)
{
  int error_occurred = 0;
  FIX_UNUSED (additional_error);

  /* checks for required options */
  if (args_info->MODE_group_counter == 0)
    {
      fprintf (stderr, "%s: %d options of group MODE were given. One is required%s.\n", prog_name, args_info->MODE_group_counter, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  

  /* checks for dependences among options */
  if (args_info->new_given && ! args_info->node_dir_given)
    {
      fprintf (stderr, "%s: '--new' ('-N') option depends on option 'node-dir'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  if (args_info->node_dir_given && ! args_info->new_given)
    {
      fprintf (stderr, "%s: '--node-dir' ('-d') option depends on option 'new'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  if (args_info->key_given && ! args_info->new_given)
    {
      fprintf (stderr, "%s: '--key' ('-k') option depends on option 'new'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  if (args_info->ssl_ca_file_given && ! args_info->new_given)
    {
      fprintf (stderr, "%s: '--ssl-ca-file' option depends on option 'new'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }

  return error_occurred;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cluster_cmdline_parser_params.check_ambiguity
 * @param override @see cluster_cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cluster_cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  char **string_field;
  FIX_UNUSED (field);

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  FIX_UNUSED (default_value);
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_FLAG:
    *((int *)field) = !*((int *)field);
    break;
  case ARG_STRING:
    if (val) {
      string_field = (char **)field;
      if (!no_free && *string_field)
        free (*string_field); /* free previous string */
      *string_field = gengetopt_strdup (val);
    }
    break;
  default:
    break;
  };


  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
  case ARG_FLAG:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


int
cluster_cmdline_parser_internal (
  int argc, char **argv, struct cluster_args_info *args_info,
                        struct cluster_cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error_occurred = 0;
  struct cluster_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cluster_cmdline_parser_init (args_info);

  cluster_cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "new",	0, NULL, 'N' },
        { "mod",	0, NULL, 'M' },
        { "info",	0, NULL, 'I' },
        { "force-gc",	0, NULL, 'G' },
        { "node-dir",	1, NULL, 'd' },
        { "key",	1, NULL, 'k' },
        { "ssl-ca-file",	1, NULL, 0 },
        { "config-dir",	1, NULL, 'c' },
        { "batch-mode",	0, NULL, 'b' },
        { "debug",	0, NULL, 'D' },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "hVNMIGd:k:c:bD", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cluster_cmdline_parser_print_help ();
          cluster_cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->version_given),
              &(local_args_info.version_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "version", 'V',
              additional_error))
            goto failure;
          cluster_cmdline_parser_free (&local_args_info);
          return 0;
        
          break;
        case 'N':	/* Creates a new SX cluster with a local node.  */
        
          if (args_info->MODE_group_counter && override)
            reset_group_MODE (args_info);
          args_info->MODE_group_counter += 1;
        
          if (update_arg( 0 , 
               0 , &(args_info->new_given),
              &(local_args_info.new_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "new", 'N',
              additional_error))
            goto failure;
        
          break;
        case 'M':	/* Modifies an existing SX cluster.  */
        
          if (args_info->MODE_group_counter && override)
            reset_group_MODE (args_info);
          args_info->MODE_group_counter += 1;
        
          if (update_arg( 0 , 
               0 , &(args_info->mod_given),
              &(local_args_info.mod_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "mod", 'M',
              additional_error))
            goto failure;
        
          break;
        case 'I':	/* Shows status and details of a running cluster.  */
        
          if (args_info->MODE_group_counter && override)
            reset_group_MODE (args_info);
          args_info->MODE_group_counter += 1;
        
          if (update_arg( 0 , 
               0 , &(args_info->info_given),
              &(local_args_info.info_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "info", 'I',
              additional_error))
            goto failure;
        
          break;
        case 'G':	/* Force a garbage collection cycle on all noeds.  */
        
          if (args_info->MODE_group_counter && override)
            reset_group_MODE (args_info);
          args_info->MODE_group_counter += 1;
        
          if (update_arg( 0 , 
               0 , &(args_info->force_gc_given),
              &(local_args_info.force_gc_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "force-gc", 'G',
              additional_error))
            goto failure;
        
          break;
        case 'd':	/* Path to the node directory.  */
        
        
          if (update_arg( (void *)&(args_info->node_dir_arg), 
               &(args_info->node_dir_orig), &(args_info->node_dir_given),
              &(local_args_info.node_dir_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "node-dir", 'd',
              additional_error))
            goto failure;
        
          break;
        case 'k':	/* File containing a pre-generated admin authentication token or stdin if \"-\" is given (default autogenerate token)..  */
        
        
          if (update_arg( (void *)&(args_info->key_arg), 
               &(args_info->key_orig), &(args_info->key_given),
              &(local_args_info.key_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "key", 'k',
              additional_error))
            goto failure;
        
          break;
        case 'c':	/* Path to SX configuration directory.  */
        
        
          if (update_arg( (void *)&(args_info->config_dir_arg), 
               &(args_info->config_dir_orig), &(args_info->config_dir_given),
              &(local_args_info.config_dir_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "config-dir", 'c',
              additional_error))
            goto failure;
        
          break;
        case 'b':	/* Turn off interactive confirmations and assume yes for all questions.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->batch_mode_given),
              &(local_args_info.batch_mode_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "batch-mode", 'b',
              additional_error))
            goto failure;
        
          break;
        case 'D':	/* Enable debug messages.  */
        
        
          if (update_arg((void *)&(args_info->debug_flag), 0, &(args_info->debug_given),
              &(local_args_info.debug_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "debug", 'D',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          /* SSL CA certificate file of the SX cluster (same file as in httpd configuration).  */
          if (strcmp (long_options[option_index].name, "ssl-ca-file") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->ssl_ca_file_arg), 
                 &(args_info->ssl_ca_file_orig), &(args_info->ssl_ca_file_given),
                &(local_args_info.ssl_ca_file_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "ssl-ca-file", '-',
                additional_error))
              goto failure;
          
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CLUSTER_CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */

  if (args_info->MODE_group_counter > 1)
    {
      fprintf (stderr, "%s: %d options of group MODE were given. One is required%s.\n", argv[0], args_info->MODE_group_counter, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  


  if (check_required)
    {
      error_occurred += cluster_cmdline_parser_required2 (args_info, argv[0], additional_error);
    }

  cluster_cmdline_parser_release (&local_args_info);

  if ( error_occurred )
    return (EXIT_FAILURE);

  if (optind < argc)
    {
      int i = 0 ;
      int found_prog_name = 0;
      /* whether program name, i.e., argv[0], is in the remaining args
         (this may happen with some implementations of getopt,
          but surely not with the one included by gengetopt) */

      i = optind;
      while (i < argc)
        if (argv[i++] == argv[0]) {
          found_prog_name = 1;
          break;
        }
      i = 0;

      args_info->inputs_num = argc - optind - found_prog_name;
      args_info->inputs =
        (char **)(malloc ((args_info->inputs_num)*sizeof(char *))) ;
      while (optind < argc)
        if (argv[optind++] != argv[0])
          args_info->inputs[ i++ ] = gengetopt_strdup (argv[optind-1]) ;
    }

  return 0;

failure:
  
  cluster_cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}
