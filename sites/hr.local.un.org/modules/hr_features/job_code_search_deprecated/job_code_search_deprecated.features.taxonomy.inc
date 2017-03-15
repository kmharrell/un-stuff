<?php
/**
 * @file
 * job_code_search_deprecated.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function job_code_search_deprecated_taxonomy_default_vocabularies() {
  return array(
    'job_network_deprecated' => array(
      'name' => 'Job Network (Deprecated)',
      'machine_name' => 'job_network_deprecated',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
