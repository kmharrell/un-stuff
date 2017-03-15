<?php
/**
 * @file
 * hr_document.file_type.inc
 */

/**
 * Implements hook_file_default_types().
 */
function hr_document_file_default_types() {
  $export = array();

  $file_type = new stdClass();
  $file_type->disabled = FALSE; /* Edit this to true to make a default file_type disabled initially */
  $file_type->api_version = 1;
  $file_type->type = 'handbook_doc';
  $file_type->label = 'Handbook Doc';
  $file_type->description = 'HR Handbook Document Files';
  $file_type->mimetypes = array(
    0 => 'text/plain',
    1 => 'application/msword',
    2 => 'application/vnd.ms-excel',
    3 => 'application/pdf',
    4 => 'application/vnd.ms-powerpoint',
    5 => 'application/vnd.oasis.opendocument.text',
    6 => 'application/vnd.oasis.opendocument.spreadsheet',
    7 => 'application/vnd.oasis.opendocument.presentation',
    8 => 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet',
    9 => 'application/vnd.openxmlformats-officedocument.presentationml.presentation',
    10 => 'application/vnd.openxmlformats-officedocument.wordprocessingml.document',
    11 => 'application/vnd.ms-excel.addin.macroEnabled.12',
    12 => 'application/vnd.ms-excel.sheet.binary.macroEnabled.12',
    13 => 'application/vnd.ms-excel.sheet.macroEnabled.12',
    14 => 'application/vnd.ms-excel.template.macroEnabled.12',
    15 => 'application/vnd.ms-pki.seccat',
    16 => 'application/vnd.ms-pki.stl',
    17 => 'application/vnd.ms-powerpoint.addin.macroEnabled.12',
    18 => 'application/vnd.ms-powerpoint.presentation.macroEnabled.12',
    19 => 'application/vnd.ms-powerpoint.slideshow.macroEnabled.12',
    20 => 'application/vnd.ms-powerpoint.template.macroEnabled.12',
    21 => 'application/vnd.ms-word.document.macroEnabled.12',
    22 => 'application/vnd.ms-word.template.macroEnabled.12',
    23 => 'application/vnd.ms-xpsdocument',
    24 => 'application/vnd.oasis.opendocument.chart',
    25 => 'application/vnd.oasis.opendocument.database',
    26 => 'application/vnd.oasis.opendocument.formula',
    27 => 'application/vnd.oasis.opendocument.graphics',
    28 => 'application/vnd.oasis.opendocument.graphics-template',
    29 => 'application/vnd.oasis.opendocument.image',
    30 => 'application/vnd.oasis.opendocument.presentation-template',
    31 => 'application/vnd.oasis.opendocument.spreadsheet-template',
    32 => 'application/vnd.oasis.opendocument.text-master',
    33 => 'application/vnd.oasis.opendocument.text-template',
    34 => 'application/vnd.oasis.opendocument.text-web',
    35 => 'application/vnd.openxmlformats-officedocument.presentationml.slideshow',
    36 => 'application/vnd.openxmlformats-officedocument.presentationml.template',
    37 => 'application/vnd.openxmlformats-officedocument.spreadsheetml.template',
    38 => 'application/vnd.openxmlformats-officedocument.wordprocessingml.template',
  );
  $export['handbook_doc'] = $file_type;

  return $export;
}
